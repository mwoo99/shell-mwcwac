#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "proj.h"

void main(){
  printf("Entering the big MAC\nType EXIT to leave\n\n");
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

void parse(char in[], char* cmd[]){  
  char *p = in;
  char *s;
  int x = 0;;
  
  while(p){
    s = strsep(&p," ");
    cmd[x] = s;
    x++;
  }
  cmd[x] = 0; 
}

int run(){
  char input[45];
  char* cmds[10];

  printf(">");
  fgets(input,sizeof(input),stdin);
  while(strncmp(input,"EXIT\n",sizeof(input)) != 0){
    char* r = strstr(input,"\n");
    *r = 0;
    
    parse(input,cmds);

    /*int t = 0;
    while (cmds[t]){
      printf("%d: %s\n",t, cmds[t]);
      t++;
      }*/
    
    if(exe(cmds)){
      return -1;
    }
    printf(">");
    fgets(input,sizeof(input),stdin);
  }
  
  return 0;
}

int exe(char * cmd[]){
  int i = fork();
  if (!i){
    //printf("My PID: %d\n", getpid());
    //printf("PPID: %d\n", getppid());
    execvp(cmd[0],cmd);
    kill(getpid(),9);
  }
  wait();
  return 0;
}
