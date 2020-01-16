/**************************************************************************
 * file:               hw9_1.c
 * author:             Yufan Xu
 * assignment:         homework 9_1
 * description:        this program simulates the action of bash
 *                     arguments
 * date created:       10/23/2018
 * date last modified: 10/25/2018
 * date due:           10/25/2018
 *************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    pid_t pid;
    int stat;

    char *s1 = "/bin/";
    char *s2 = argv[1];

    char *result = malloc(strlen(s1) + strlen(s2) + 1);

    strcpy(result, s1);
    strcat(result, s2);

    pid = fork();

    if (pid == 0) {
        int ret = execv(result, &argv[1]);
        return ret;
    } else {
        wait(&stat);
    }

    free(result);
    return 0;
}