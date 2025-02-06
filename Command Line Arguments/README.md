# Command Line Arguments in C
The most important function of C is the main() function. It is mostly defined with a return type of int and without parameters.

```c
int main() { 
    ... 
}
```

Command-line arguments are the **values given after the name of the program in the command-line shell** of Operating Systems.
We can also give command-line arguments in C. Command-line arguments are **handled by the main() function** of a C program.

## To pass command-line arguments:
We define main() with two arguments: 
- the first argument is the number of command-line arguments.
- the second is a list of command-line arguments.
```c
int main(int argc, char *argv[]) {...}
or 
int main(int argc, char **argv) {...}
```

Here,
- argc (ARGument Count) is an integer variable that stores the number of command-line arguments passed by the user including the name of the program.
- The value of argc should be non-negative.
- argv (ARGument Vector) is an array of character pointers listing all the arguments.
  
## For example:

```c++
#include<stdio.h>

int main(int argc, char *argv[]) {

  printf("The number of arguments = %d.\n", argc);

  printf("The arguments are: \n")
  for(int i=0;i<argc;i++){
    printf("arg[%d]: %s\n", i, argv[i]);
  }

  return 0;
}
```

compile this code on your Linux machine. 

    gcc filename.c

and run. 

    ./a.out first_arg second_arg

**Output**
```console
The number of arguments = 3.
arg[0]: ./a.out
arg[1]: first_arg
arg[2]: second_arg
```

