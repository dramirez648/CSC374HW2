/* Daniel Ramirez
   CSC 374 
   Homework 2
*/
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

int sibling_pid;
int numSec;

int main(int argc, char * argv[] ){
 	sibling_pid = atoi(argv[1]);
 	numSec = atoi(argv[2]);

 	if(sibling_pid < 0) 
 	{
 		printf("Illegal pid.\n");
 		return(EXIT_FAILURE);
 	}

 	if(numSec < 0) 
 	{
 		printf("Illegal number of seconds.\n");
 		return(EXIT_FAILURE);
 	}
 	else 
 	{
		while(numSec != 0)
		{
    		printf("Clock 00:00:%d \n", numSec);
    		sleep(1);
    		numSec--;
    		
    		if(numSec == 0)
			{
    			break;
   			}
    	}
    }

 printf("Clock Ding! Ding! Ding!\n");
 kill(sibling_pid,SIGALRM);
return(EXIT_SUCCESS);
}
