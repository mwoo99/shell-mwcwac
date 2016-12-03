#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>


int exe(char * cmd[]){
  int red = finRed(cmd);
  char* mark = cmd[0];

  if (red){
    char *re = cmd[red];
    int f;
    int nf;
    int cf;
    
    if (!strcmp(re,"<")){
      f = fork();
      
	if(!f){ 
	 re = cmd[(red + 1)];
	 nf = open(re, O_RDONLY);
	 
	 cf = dup(0);
	 dup2(nf,0);
	 
	 cmd[red] = 0;
	 
	 execvp(cmd[0],cmd);
	 dup2(cf,0);
      close(nf);	
      }
    }
    
    else if(!strcmp(re,">")){
      f = fork();
	 
	if(!f){ 
	 re = cmd[(red + 1)];
	 nf = open(re, O_CREAT | O_WRONLY, 00755);
	 
	 cf = dup(1);
	 dup2(nf,1);
	 
	 cmd[red] = 0;
	 
	 execvp(cmd[0],cmd);
	 // THIS DOESN"T APPEAR SINCE EXECVP EXITS	
      }
    }

    else{
      char * c1[2];
      char * c2[2];
      char * s;
      int file = open(".nopipe", O_CREAT | O_RDWR | O_TRUNC, 0644);

      s = cmd[0];
      c1[0] = s;
      s = cmd[2];
      c2[0] = s;
      c1[1] = 0;
      c2[1] = 0;
      
      f = fork();
      if(!f){
	int f2 = fork();
	if(!f2){
	  dup2(file,1);
	  execvp(c1[0],c1);
	}
	else{
	  wait();
	  lseek(file,0,SEEK_SET);
	  dup2(file,0);
	  execvp(c2[0],c2);
	}
      }

      wait();
      int f3 = fork();
      if(!f3) execlp("rm","rm",".nopipe",NULL);
    }
    
    if(!f) kill(getpid(),9);
    wait();
    } //WIP for Redirections
  
  else if (!strcmp(cmd[0], "cd")){
    chdir(cmd[1]);
    }
  
  
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