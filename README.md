# get_next_line

open

#include <fcntl.h>

int open(const char *path, int flags, ...
    /* mode_t mode */ );

The open() system call opens the file specified by path.

The return value of open() is a file descriptor, a small,
nonnegative integer that is an index to an entry in the process's table of open file descriptors.

The argument flags must include one of the following access modes:
O_RDONLY, O_WRONLY, or O_RDWR.  These request opening the file read-only, write-only, or read/write, respectively.

read

#include <unistd.h>

ssize_t read(size_t count;
    int fd, void buf[count], size_t count);

read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.

On files that support seeking, the read operation commences at the file offset, and the file offset is incremented by the number of bytes read.  If the file offset is at or past the end of file, no bytes are read, and read() returns zero.

If count is zero, read() may detect the errors described below. In the absence of any errors, or if read() does not check for errors, a read() with a count of 0 returns zero and has no other effects.

LES VARIABLE SATITC ET global QUI DOIVENT ETRE init a 0 le mieu cest de pas le faire car c'est fait pas la bss a se renseigne 