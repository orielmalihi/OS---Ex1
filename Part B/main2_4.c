#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    	pid_t childPID = fork();
	
	if( childPID == 0){
		char* args[2] = {"./task1", NULL};
		execvp(args[0], args);
	}
	childPID = fork();

	if( childPID == 0){
		char* args[2] = {"./task2", NULL};
		execvp(args[0], args);
	}
	childPID = fork();

	if( childPID == 0){
		char* args[2] = {"./task3", NULL};
		execvp(args[0], args);
	}
	usleep(20000000);

    return 0;
}
