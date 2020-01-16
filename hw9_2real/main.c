/**************************************************************************
 * file:               hw9_2.c
 * author:             Yufan Xu
 * assignment:         homework 9_2
 * description:        this program forks 5 child processes
 * date created:       10/23/2018
 * date last modified: 10/25/2018
 * date due:           10/25/2018
 *************************************************************************/

#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void childFunc(int i) {
    char buffer[50];
    struct timePtr* ptr;
    time_t time1;
    time1 = time(NULL);

    ptr = localtime(&time1);
    strftime(buffer, sizeof(buffer), "%A, %x %X\n", ptr);
    printf("Child %d: %s",i+1, buffer);
    exit(0);
}

int main() {
    pid_t pid;
    int i, stat;

    for (i = 0; i < 5; i ++) {
        pid = fork();
        if (pid == 0) {
            childFunc(i);
        }
    }

    printf("Waiting for children...\n");

    for (i = 0; i < 5; i ++) {
        wait(&stat);
    }
    waitpid(pid, &stat, 0);

    if (stat == 0) {
        printf("Done\n");
    }
    return 0;
}