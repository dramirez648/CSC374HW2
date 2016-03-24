/* Daniel Ramirez
   CSC 374 
   Homework 2
*/
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_LINE        256
#define ALARMCLOCK_PROG "alarmClock"
#define SLEEPINGSTUDENT_PROG "sleepingStudent"

int main(){
	int status;
	char   pid[MAX_LINE];
	char   secs[MAX_LINE];

	printf("How many seconds shall the student be allowed to sleep?\n");
	fgets(secs, MAX_LINE, stdin);
	
	pid_t child_pid;
	pid_t sleepingStudent_pid = fork();

	if(sleepingStudent_pid < 0)
	{	
		printf("Failed to fork. \n");
	}

	else if(sleepingStudent_pid == 0)
	{
		execl(SLEEPINGSTUDENT_PROG, SLEEPINGSTUDENT_PROG, NULL);
		child_pid = getpid();
	}

	pid_t alarmClock_pid = fork();

	if(alarmClock_pid < 0)
	{
		printf("Failed to fork.\n");
	}

	else if(alarmClock_pid == 0)
	{
		execl(ALARMCLOCK_PROG, ALARMCLOCK_PROG, pid, secs, NULL);
	}

	waitpid(child_pid, &status, WNOHANG);
	waitpid(alarmClock_pid, &status, WNOHANG);
	printf("Such a good student!");
	return(EXIT_SUCCESS);
}

