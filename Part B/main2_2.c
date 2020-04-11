#define _GNU_SOURCE
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 10000
#define CYCLES 20

// global var
char child_stack[STACK_SIZE + 1];

void my_print(const char* text){
	for(int i =0; i<CYCLES; i++){
		printf("Hello from %s\n" ,text);
		usleep(1000000);
		}
}

int child_one(void* params){
	my_print("child_thread_ONE");
	return 0;
}

int child_two(void* params){
	my_print("child_thread_TWO");
	return 0;
}


int main(void)
{		
 	int resultOne = clone(child_one, child_stack+STACK_SIZE,CLONE_PARENT,0);
	int resultTwo = clone(child_two, child_stack+STACK_SIZE,CLONE_PARENT,0);
	printf("clone result one = %d , clone result two = %d\n", resultOne, resultTwo);

	my_print("parent");
	return 0;
}
