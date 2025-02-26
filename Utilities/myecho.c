#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define False 0
#define True  1

int main(int argc, char **argv){

    if(argc>1){
        char new_line = True;
        if(strcmp(argv[1], "-n") == 0){
            new_line = False;
        }

        int i=1;
        if(new_line == False) i++;

        for(;i<argc;i++){
            fprintf(stdout, "%s", argv[i]);
            if(argv[i+1] != NULL) printf(" ");
        }

        if(new_line == True) printf("\n");
    }
    else {
        exit(-1);
    }
    
    return 0;
}