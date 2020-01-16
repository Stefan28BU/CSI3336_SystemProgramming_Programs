/*************************************************************************
 * filename:           tail.c
 * author:             Yufan Xu
 * assignment:         CSI 3336 Homework 8
 * description:        this programs replaces the tail command in bash
 * date created:       10/15/2018
 * data last modified: 10/16/2018
 * date due:           10/16/2018
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    /*check if number of arguments is valid*/
    if (argc > 3) {
        printf("Wrong number of arguments");
        return -1;
    }
    int size;
    char *fileName;

    /*determine condition*/
    if (argc == 3) {
        fileName = argv[2];
        size = atoi(argv[1]);
    }
    else if (argc == 2) {
        fileName = argv[1];
        size = 120;
    }

    /*read file*/
    FILE *fp = fopen(fileName, "r");

    /*check if file exists*/
    if (fp == NULL) {
        printf("Bad file\n");
        return -1;
    }

    /*read char from end*/
    fseek(fp, -size, SEEK_END);

    int i;
    char ch;

    /*print result*/
    for (i = size - 1; i > -1; i --) {
        fread(&ch, sizeof(char), 1, fp);
        printf("%c", ch);
    }
    fclose(fp);

    return 0;
}