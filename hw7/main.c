/*************************************************************************
 * filename:           catBase.c
 * author:             Yufan Xu
 * assignment:         CSI 3336 Homework 7
 * description:        this programs replaces the cat command in bash
 * date created:       10/15/2018
 * data last modified: 10/16/2018
 * date due:           10/16/2018
 ************************************************************************/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fptr;
    char *fileName = argv[1];

    /*open file*/
    fptr = fopen(fileName, "r");

    /*display error message if failed to open*/
    if (!fptr) {
        printf("File Not Open");
    }

    /*read first char in the file*/
    char ch = fgetc(fptr);

    /*if not eof, get next char until reach the end*/
    while (ch != EOF) {
        putchar(ch);
        ch = fgetc(fptr);
    }

    /*close file*/
    fclose(fptr);

    return 0;
}