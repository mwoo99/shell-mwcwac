#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    if(*s){
    	cmd[x] = s;
    	x++;
    }
  }
  cmd[x] = 0; 
}

int finRed(char* cmd[]){//WIP for Redirections
  int c = 0;
  while(cmd[c]){
    if(!strcmp(cmd[c],"<") || !strcmp(cmd[c],">") || !strcmp(cmd[c],"|")){
      return c;
    }      
    c++;
  }
  
  return 0;
}