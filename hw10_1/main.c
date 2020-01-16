/**************************************************************************
 * file:               hw10_1.c
 * author:             Yufan Xu
 * assignment:         homework 10_1
 * description:        this program forks child process by taking cmd line
 *                     arguments
 * date created:       10/28/2018
 * date last modified: 10/30/2018
 * date due:           10/30/2018
 *************************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void childFunc(int i) {
    i += 1;
    printf("PID is: %d, and its Child: %d \n", getpid(), i);

    exit(i);
}

int main(int argc, char **argv) {
    pid_t pid;
    int i, N, stat;

    N = atoi(argv[1]);

    for (i = 0; i < N; i ++) {
        pid = fork();
        if (pid == 0) {
            childFunc(i);
        }
        else {
            wait(&stat);
        }
    }
    for (i = 0; i < N; i ++) {
        printf("Child: %d %s", i+1, "is done\n");
    }

    return 0;
}