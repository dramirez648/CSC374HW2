/* Daniel Ramirez
   CSC 374 
   Homework 2
*/
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int canSleep;

void signalHandler(int signal) {
 	canSleep = 0;
}

int main() {
	struct sigaction act;

 	memset(&act, '\0', sizeof(act));
 	act.sa_handler = signalHandler;
 	sigaction(SIGALRM, &act, NULL);

 	canSleep = 1;

 	while  (canSleep) {
 		printf("Student: \"(snore)\"\n");
  		sleep(1);
 	}
 	
printf("Student: \"Okay, okay. I'll wake up! \"\n");

return(EXIT_SUCCESS);

}
