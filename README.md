Big Mac
by Conan Wong, Anthony Chen, Michael Woo

Features:
	Forks and executes
	Simple redirection and piping
	Multiple commands on one line

Unsuccessfully implemented features:
	Couldn't replace the beginning of the current working directory with ~.
	(/home/students/2017/<NAME>/...  replaced with ~/...)

Bugs:
	

Functions:
void main()
     inputs: --
     returns: --

     Prints the enter message and runs the shell
     
void error()
     inputs: --
     returns: --
     
     Prints an error message

void parse(char in[], char* cmd[])
     inputs: char in[], char* cmd[]
     returns: --
     
     Processes input and separates it by spaces

int run()
    inputs: --
    returns: --
    
    Uses fgets to take user input. Parse and execute those functions. Handles EXIT and cd commands.

int exe(char * cmd[])
    inputs: char * cmd[]
    returns: int
   
    Checks and handles for redirection and piping. If there is redirection, fork and correspondly redirect. If there is piping, fork and use the output of one command as the input of another. Else just run() just executes the command and kills the process afterwards. 

int finRed(char* cmd[])
    inputs: char* cmd[]
    return: int
    
    Returns the occurrence of redirection or piping
    
    		 
