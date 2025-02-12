#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main ( ){
    printf("Th Parent PID = %d\n", getpid());

    int ret_pid = fork();

    if(ret_pid == -1){
        printf("Failed to create a new process\n") ;
    }
    else if(ret_pid>0) {
        printf("Success! your PID = %d, and child PID = %d\n", getpid(), ret_pid) ;
    }
    else if(ret_pid == 0) {
        printf("I'm The child and my PID = %d, my parent PID = %d. \n", getpid(), getppid( ) ) ;
    }
    return 0;

}