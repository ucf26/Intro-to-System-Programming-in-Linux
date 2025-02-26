#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main(){
    char buf[MAX_SIZE];
    char *cwd = getcwd(buf, MAX_SIZE);
    if(NULL == cwd){
        fprintf(stderr, "error = %s\n", strerror(errno));
        exit(-1);
    }
    else {
        printf("path = %s,\n", cwd);
    }
}
    