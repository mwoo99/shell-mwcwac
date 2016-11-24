#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "proj.h"

void main(){
  printf("\nEntering the big MAC\nType EXIT to leave\n\n");
  int x = run();
  
  if (x){
    error();
    return;
  }
  printf("Exiting MAC bash. Thanks for using us!\n");
}

void error(){
  printf("Something went wrong!\n%s\n",strerror(errno));
}

void parse(char in[], char* cmd[]){//processes in and adjusts cmd 
  char *p = in;
  char *s;
  int x = 0;

  while(in[(strlen(in) - 1)] == ' '){//removes whitespace behind semicolon
    in[(strlen(in) - 1)] = 0;
  }
  while(*p == ' '){//removes whitespace in front of semicolon
    p++;
  }
  
  while(p){//most of the changing done to cmd
    s = strsep(&p," ");
    cmd[x] = s;
    x++;
  }
  cmd[x] = 0; 
}

int run(){
  char input[45];
  char* cmds[20];
  char cwd[256];
  
  char* semiP;
  char* procP;

  getcwd(cwd,sizeof(cwd));
  printf("TacoBigMACshell:%s$", cwd);
  
  fgets(input,sizeof(input),stdin);
  while(strncmp(input,"EXIT\n",sizeof(input)) != 0){
    char* r = strstr(input,"\n");
    *r = 0;

    semiP = input;
    while(semiP){
      procP = strsep(&semiP,";");
      parse(procP,cmds);
      if(exe(cmds)){
	return -1;
      }
    }
    
    getcwd(cwd,sizeof(cwd));
    printf("TacoBigMACshell:%s$", cwd);
    
    fgets(input,sizeof(input),stdin);
  }
  
  return 0;
}

int exe(char * cmd[]){
  int red = checkRed(cmd);
  char* mark = cmd[0];
  
  if (strcmp(cmd[0], "cd") == 0){
    chdir(cmd[1]);
    }

  /*if (red){
    int c = 0;
    while(c){
    }
    }*/ //WIP for Redirections
  
  else{    
    int i = fork();
    if (!i){
      //printf("My PID: %d\n", getpid());
      //printf("PPID: %d\n", getppid());
      execvp(cmd[0],cmd);
      kill(getpid(),9);
    }    
  wait();
  }  
  return 0;
}

int checkRed(char* cmd[]){//WIP for Redirections
  int c = 0;
  while(cmd[c] != 0){
    if(strcmp(cmd[c],"<")){
      return 1;}
    
    if(strcmp(cmd[c],">")){
      return 2;}
    
    if(strcmp(cmd[c],"|")){
      return 3;}
      
    c++;
  }
  
  return 0;
}
