#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "proj.h"

void main(){
  printf("Entering the big MAC\nType EXIT to leave\n");
  int x = run();
  
  if (x){
    error();
    return;
  }
  printf("Exit MAC bash\n");
}

void error(){
  printf("Something went wrong!\n%s\n",strerror(errno));
}

int run(){
  char input[100]
  while(!strcmp(input,"EXIT")){
    fgets(input,sizeof(input),stdin);
    if(exe(input)){
      return -1;
    }
  }
  
  return 0;
}

int exe(char[] in){
  int i = fork();
  if (!i){
    
  }
  
  return 0;
}
