#include<stdio.h>

int main(int argc, char *argv[]) {

  printf("The number of arguments = %d.\n", argc);

  printf("The arguments are: \n")
  for(int i=0;i<argc;i++){
    printf("arg[%d]: %s\n", i, argv[i]);
  }

  return 0;
}
