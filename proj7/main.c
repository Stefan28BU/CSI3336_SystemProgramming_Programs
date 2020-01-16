/**************************************************************************
 * file:               easterEggs.c
 * author:             Yufan Xu
 * assignment:         project 7
 * description:        this program processes the command-line to obtain a
 *                     filename. It spawn five child processes assigning
 *                     each child a color
 * date created:       11/1/2018
 * date last modified: 11/1/2018
 * date due:           11/1/2018
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/*create enumerated data types and assign each to a number*/
enum color {red=0, green=1, blue=2, yellow=3, orange=4};

/*function to change directories and count the frequency*/
int countColor(char *directory, char *fileName, int c, int *count) {
    DIR *dp;
    FILE *fp;
    struct dirent *entry;
    struct stat status;
    int color;

    /*check if directory exists*/
    if ((dp = opendir(directory)) != NULL) {
        chdir(directory);
    }
    else {
        printf("BAD DIRECTORY\n");
        exit(1);
    }

    while ((entry = readdir(dp)) != NULL) {

        /*get the status of current entry name*/
        lstat(entry->d_name, &status);

        /*check if the entry name is a directory*/
        if (S_ISDIR(status.st_mode)) {

            /*skip the auto generated link to current and parent directory*/
            if (strcmp(".", entry->d_name) != 0 &&
                strcmp("..", entry->d_name) != 0) {
                countColor(entry->d_name, fileName, c, count);
            }
        }

        /*if a file is found, determine if it is the file, if true, count*/
        else {
            if (strcmp(fileName, entry->d_name) == 0) {
                fp = fopen(fileName, "rb");
                while (fread(&color, sizeof(int), 1, fp) > 0) {
                    if (color == c) {
                        (*count)++;
                    }
                }
                fclose(fp);
            }
        }
    }
    chdir("..");
    closedir(dp);

    return (*count);
}

int main(int argc, char **argv) {
    int i, j, k = 0, freqSet[5][2];
    pid_t pidArr[5];

    /*check for valid inputs*/
    if (argc != 2) {
        printf("Wrong Input\n");
        exit(1);
    }

    for (i = red; i <= orange; i ++) {

        /*check for pipping*/
        if (pipe(freqSet[i]) == -1) {
            printf("BAD PIPPING\n");
            exit(1);
        }

        /*spawn a child process for current color*/
        pidArr[i] = fork();

        /*check if failed*/
        if (pidArr[i] == -1) {
            printf("FAILED\n");
            exit(1);
        }

        /*child*/
        else if (pidArr[i] == 0) {
            k = countColor(".", argv[1], i, &k);
            write(freqSet[i][1], &k, sizeof(int));
            exit(0);
        }

        /*parent*/
        else {
            read(freqSet[i][0], &j, sizeof(int));

            if (i == red) {
                printf("%-10s%d\n", "red:", j);
            }
            else if (i == green) {
                printf("%-10s%d\n", "green:", j);
            }
            else if (i == blue) {
                printf("%-10s%d\n", "blue:", j);
            }
            else if (i == yellow) {
                printf("%-10s%d\n", "yellow:", j);
            }
            else if (i == orange) {
                printf("%-10s%d\n", "orange:", j);
            }
        }
    }

    /*wait for all children to finish*/
    for (i = 0; i < 5; i ++) {
        wait(NULL);
    }

    return 0;
}