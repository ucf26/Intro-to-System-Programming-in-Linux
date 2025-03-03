#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 4096

void print_error(int num){
    fprintf(stderr, "%s\n", strerror(num));
}


int main(int argc, char **argv){
    // only works for one source and one destination
    if(argc != 3){
        printf("Enter one valid source path and one valid distination path\n");
        exit(-1);
    }

    struct stat src, dist;

    int src_fd = open(argv[1], O_RDONLY);

    if(src_fd < 0){
        printf("Failed opening source file.\n");
        print_error(errno);
        exit(-1);
    }

    int src_stat = fstat(src_fd, &src);
    if(src_stat < 0){
        print_error(errno);
        exit(-1);
    }

    if(S_ISDIR(src.st_mode)){
        printf("Source should be a file.\n");
        exit(-1);
    }

    int dist_fd = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, src.st_mode);
    if(dist_fd < 0){
        printf("Failed opening Distination file.\n");
        print_error(errno);
        exit(-1);
    }

    char buf[MAX_SIZE];
    int numRead;
    while((numRead = read(src_fd, buf, sizeof(buf))) > 0){
        int totWritten = 0;
        while(totWritten < numRead){
            int curWritten = write(dist_fd, buf, numRead - totWritten);
            if(curWritten < 0){
                print_error(errno);
                exit(-1);
            }
            totWritten += curWritten;
        }
    }

    if(numRead == -1){
        print_error(errno);
        exit(-1);
    }
    
    close(src_fd);
    close(dist_fd);

    return 0;
}