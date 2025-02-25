#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define COUNT 100

void write_all(const int fd, const char *buf, int count){
    int numWritten = 0;
    while(numWritten < count){
        int curWritten = write(STDOUT_FILENO , buf, count - numWritten);
        if(-1 == curWritten){
            fprintf(stderr, "error = %s\n", strerror(errno));
            exit(-1);
        }
        numWritten += curWritten;
    }
}


int main(int argc, char *argv[]){
    char buf[COUNT];
    if(argc == 1){
        int numRead;
        while((numRead = read(STDIN_FILENO, buf, COUNT)) > 0){
                if(-1 == numRead){
                    fprintf(stderr, "error = %s\n", strerror(errno));
                    exit(-1);
                    break;
                }
                write_all(STDOUT_FILENO , buf, numRead);
            }
    }
    else {
        for(int i=1;i<argc;i++){
            int fd;
            if(strcmp(argv[i], "-") == 0){ 
                fd = STDIN_FILENO;
            }
            else {
                fd = open(argv[i], O_RDONLY);
                if(-1 == fd){
                    fprintf(stderr, "error = %s\n", strerror(errno));
                    exit(-1);
                }
            }
            
            int numRead;
            while((numRead = read(fd, buf, COUNT)) > 0){
                if(-1 == numRead){
                    fprintf(stderr, "error = %s\n", strerror(errno));
                    exit(-1);
                    break;
                }
                write_all(STDOUT_FILENO , buf, numRead);
            }

            if (fd != STDIN_FILENO) {
                close(fd);
            }

        }

    }
    return 0;
}