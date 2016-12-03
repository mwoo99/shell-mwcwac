Big Mac
by Conan Wong, Anthony Chen, Michael Woo

Features:

	Forks and executes
	Simple redirection and piping
	Multiple commands on one line
	Makes Doritos Locos Tacos

Unsuccessfully implemented features:

	Couldn't replace the beginning of the current working directory with ~.
	(/home/students/2017/<NAME>/...  replaced with ~/...)
	Was unable to do infinite piping /did not have the time.
	Autocomplete, since it requires a library outside of our knowledge.

Bugs:
	When you repeatedly run an unknown command, e.g. (moo), you will be forced
	to exit the program.
	Tacos will be cold.

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
     
     Processes input and separates it by spaces.

int run()
    inputs: --
    returns: --
    
    Uses fgets to take user input. Parse and execute those functions. Handles ExIT and cd commands.

int exe(char * cmd[])
    inputs: char * cmd[]
    returns: int
   
    Checks and handles for redirection and piping. If there is redirection, for  and correspondly redirect.
    If there is piping, fork and use the output of one command as the input of another. 
    Else just run() just executes the command and kills the process afterwards. 

int finRed(char* cmd[])
    inputs: char* cmd[]
    returns: int
    
    Returns the occurrence of redirection or piping (return value > 0)
    If neither redirection nor piping is found, then 0 is returned.
    
    		 
