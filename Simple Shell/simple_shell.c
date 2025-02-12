#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char* argv[]){

	while(1){
		char buff[100];
		printf("Enter ya basha >> ");
		fgets(buff, 100, stdin);
		int len = strlen(buff);
		buff[len-1] = 0;
		if(strlen(buff) == 0)
			continue;

		int retpid = fork();

		if(retpid > 0){
			printf("this is the parent, my child id = %d, while my id = %d\n", retpid, getpid());
			wait(NULL);
		}
		else if(retpid == 0){
			char * newargv[] = {NULL};
			char * newenvp[] = {NULL};
			execve(buff, newargv, newenvp);
			printf("This text is printed in case of failure.\n");
		}
		else {
			printf("fork failed\n");
		}		
	}

	return 0;
}
