#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "proj.h"
#include "parse.c"
#include "exe.c"

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

int run(){
  char input[256];
  char* cmds[20];
  char cwd[256];
  
  char* semiP;
  char* procP;

  getcwd(cwd,sizeof(cwd));
  printf("TacoBigMACshell:%s$ ", cwd);
  
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
    printf("TacoBigMACshell:%s$ ", cwd);
    
    fgets(input,sizeof(input),stdin);
  }
  
  return 0;
}
