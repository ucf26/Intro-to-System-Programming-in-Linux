In summary:
In order to perform I/O on a regular file, we must first obtain a file descriptor using open(). I/O is then performed using read() and write(). After performing all I/O, we should free the file descriptor and its associated resources using close(). These system calls can be used to perform I/O on all types of files.

The fact that all file types and device drivers implement the same I/O interface allows for universality of I/O, meaning that a program can typically be used with any type of file without requiring code that is specific to the file type.

In details:
All system calls for performing I/O refer to open files using a file descriptor. A file descriptor is an unsigned integer used by a process to identify an open file. By convention, most programs expect to be able to use the three standard file descriptors.


![image info](./Screenshot%202025-02-25%20045226.png)


## The four key system calls for performing file I/O:
### open():

```c
#include <sys/stat.h> #include <fcntl.h>

int open(const char *pathname, int flags, ... /* mode_t mode */);
```

opens the file identified by pathname, returning a file descriptor used to refer to the open file in subsequent calls.

If the file doesn’t exist, open() may create it, depending on the settings of the flags bitmask argument.

The flags argument also specifies whether the file is to be opened for reading, writing, or both. The mode argument specifies the permissions to be placed on the file if it is created by this call. If the open() call is not being used to create a file, this argument is ignored and can be omitted.

### read():

```c
#include <unistd.h>

ssize_t read(int fd, void *buffer, size_t count);
```

reads at most count bytes from the open file referred to by fd and stores them in buffer.
A successful call to read() returns the number of bytes actually read, or 0 if end-of-file is encountered. On error, the usual –1 is returned. The ssize_t data type is a signed integer type used to hold a byte count or a –1 error indication.

### write():
```c
#include <unistd.h>

ssize_t write(int fd, void *buffer, size_t count);
```
writes up to count bytes from buffer to the open file referred to by fd. 
The write() call returns the number of bytes actually written, which may be less than count.

### close():
```c
#include <unistd.h>
int close(int fd);
```
is called after all I/O has been completed, in order to release the file descriptor fd and its associated kernel resources.

It is usually good practice to close unneeded file descriptors explicitly, since this makes our code more readable and reliable in the face of subsequent modifications. Furthermore, file descriptors are a consumable resource, so failure to close a file descriptor could result in a process running out of descriptors. This is a particularly important issue when writing long-lived programs that deal with multiple files, such as shells or network servers.


## cat :
a simple implementation of cat command 

### Features Added:
- Command-Line Argument:
    - accepts multiple filenames as arguments.
    - Treat the special filename - as standard input.
-  Read from Standard Input:
    - If no filenames are provided, read from stdin.
- Error Handling:
    - Print meaningful error messages to stderr using `fprintf()`.

to compile and run mycat.c:

```c
gcc mycat.c -o mycat
./mycat filename
```







