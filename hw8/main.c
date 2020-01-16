/*************************************************************************
 * filename:           catSysC.c
 * author:             Yufan Xu
 * assignment:         CSI 3336 Homework 8
 * description:        this programs replaces the cat command in bash, use
 *                     system calls
 * date created:       10/15/2018
 * data last modified: 10/16/2018
 * date due:           10/16/2018
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    char buffer[4096];

    /*check input*/
    if (argc != 2) {
        printf("Wrong number of arguments\n");
        return -1;
    }
    int fd = open(argv[1], O_RDONLY);

    /*check if file exists*/
    if (fd == -1) {
        printf("Bad file name\n");
        return -1;
    }

    /*read file and print to screen*/
    int n;
    while ((n = read(fd, &buffer, 4096)) > 0) {
        write(1, &buffer, n);
    }
    close(fd);

    return 0;
}