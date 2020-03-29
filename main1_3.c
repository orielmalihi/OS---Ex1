/*
 * main.c
 *
 *  Created on: 27.3.2020
 *      Author: oriel
 */
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <dlfcn.h>

void (*hello_msg)(char*);

bool init_lib()
{
	void* hdl = dlopen("./libhello.so",RTLD_LAZY);
	if(hdl == NULL)
		return false;
	hello_msg = (void(*)(char*))dlsym(hdl, "print_hello");
	if(hello_msg ==NULL)
		return false;
	return true;
}

int main(){
	if(init_lib())
		hello_msg("Ariel");
	else
		printf("Library was not Loaded\n");
	return 0;
}

