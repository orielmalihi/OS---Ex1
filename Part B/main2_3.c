#include <unistd.h>
#include <syslog.h>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	// creating the child that will be the deamon
	pid_t daemonPID = fork();

	if(daemonPID == 0){
		// are in thh child
		
		//moving to root directory
		chdir("/");

		//moving the procces to another session so we can close the parent procces
		setsid();

		printf("\nthe daemon is now starting..\n");

		// closing the output channels
		close((intptr_t)stdout);
		close((intptr_t)stdin);
		close((intptr_t)stderr);

		// opening log
		openlog("myDaemon", LOG_PID, LOG_DAEMON);
		syslog(LOG_NOTICE, "daemon started");
		usleep(3000000);
		syslog(LOG_NOTICE, "daemon is doing some work..");
		usleep(3000000);
		syslog(LOG_NOTICE, "daemon finished");
	}
	else{
		printf("deamon PID = %d\n", daemonPID);
	}
	return 0;
}
