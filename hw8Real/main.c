/*************************************************************************
 * filename:           head.c
 * author:             Yufan Xu
 * assignment:         CSI 3336 Homework 8
 * description:        this programs replaces the head command in bash
 * date created:       10/15/2018
 * data last modified: 10/16/2018
 * date due:           10/16/2018
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    int c;
    int i;
    size_t n;
    char *fileName;
    char *line;

    /*get different mode from the user*/
    while((c = getopt(argc, argv, "tofi:")) != -1 ) {
        switch (c) {
            case 't':
                i = 10;
                break;

            case 'o':
                i = 1;
                break;

            case 'f':
                i = 5;
                break;

            case 'i':
                fileName = argv[argc-1];
                break;

            case '?':
                break;
        }
    }

    /*open file*/
    FILE *fp = fopen(fileName, "r");

    /*check if file not exist*/
    if (fp == NULL) {
        printf("Bad file\n");
        return -1;
    }

    /*print result*/
    int j;
    for (j = 0; j < i; j ++) {
        getline(&line, &n, fp);
        printf("%s", line);
    }
    fclose(fp);

    return 0;
}
