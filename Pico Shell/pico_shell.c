#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my_string/mystring.h"

#define MAX_SIZE 100

int main(int argc, char **argv){
    char buf[MAX_SIZE];
    char *args[50];

    while(1){
        printf(">>> ");
        fgets(buf, MAX_SIZE, stdin);
        buf[str_len(buf) - 1] = '\0';

        if(str_len(buf) == 0){
            continue;
        }
        
        if(str_cmp(buf, "exit") > 0){
            break;
        }

        int retpid = fork();

        if(retpid == 0){
            int x= str_parse(buf, args);
            printf("CHILD: My PID = %d, Parent ID = %d\n", retpid, getppid());
            char **newarg = { NULL};
            printf("Execution result:\n");
            execvp(args[0], args);
            printf("exec failed \n");
            exit(-1);
        }
        else if(retpid > 0){
            int status;
            int pid = wait(&status);
            printf("PARENT: My PID = %d, Child ID = %d\n", getpid(), retpid);
        }
        else {
            printf("Failed to fork\n");
        }
    }
    return 0;
}