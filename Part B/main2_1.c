#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void my_print(const char* text){
	for(int i =0; i<20; i++){
		printf("Hello from %s\n" ,text);
		usleep(1000000);
	}
}

int main(void)
{
	// creating the child
    	pid_t childPID = fork();
	
	if( childPID == 0){
		// fork was successful! we are in child procces
		
		// now creating the grandchild 
		pid_t childPID = fork();
	
		if(childPID == 0){
			// fork was successful! now we are in grandchild procces
			my_print("grandchild");
		}
		else{
			my_print("child");
		}
	}
	else{
		my_print("parent");
	}


    return 0;
}
