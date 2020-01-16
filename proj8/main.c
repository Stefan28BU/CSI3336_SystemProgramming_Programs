/**************************************************************************
 * file:               pSum.c
 * author:             Yufan Xu
 * assignment:         project 8
 * description:        this program uses multiple processes to sum numbers
 *                     found in a file
 * date created:       11/8/2018
 * date last modified: 11/8/2018
 * date due:           11/8/2018
 *************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    int childNum, intNum, i, numPerChild, remainder, count;
    FILE *fp;
    int childSum = 0, childCount = 0;
    int *data, sum, totalSum = 0;

    int fd[2];
    pid_t pid;
    count = 0;
    struct stat fileInfo;

    /*check for valid command line input*/
    if (argc != 3) {
        perror("Wrong number of inputs\n");
        exit(1);
    }

    /*get the number child process*/
    childNum = atoi(argv[2]);

    /*read from binary file*/
    fp = fopen(argv[1], "rb");

    /*check if file is successfully opened*/
    if (!fp) {
        perror("Failed to open file\n");
        exit(1);
    }

    /*get the file size, in terms of number of integers*/
    stat(argv[1], &fileInfo);
    intNum = fileInfo.st_size / 4;

    printf("inNum: %d\n", intNum);

    /*create a buffer to read*/
    data = (int*)malloc(sizeof(int) * intNum);

    int val;

    for (i = 0; i < intNum; i ++) {
        fread(&val, sizeof(int),1, fp);
        data[i] = val;
    }
    //fread(data, sizeof(data), 1, fp);

    /*assign numbers to each child*/
    numPerChild = intNum / childNum;
    remainder = intNum % childNum;

    /*create multiple child process*/
    for (i = 0; i < childNum; i ++) {
        pipe(fd);
        pid = fork();

        if (pid == -1) {
            perror("ERROR\n");
            exit(1);
        }
        else if (pid == 0) {
            if (remainder == 0) {
                for (i = 0; i < numPerChild; i ++) {
                    childSum += data[count+i];
                }
            }
            else {
                if (childCount < remainder) {
                    for (i = 0; i < numPerChild+1; i ++) {
                        childSum += data[count+i];
                    }
                }
                else {
                    for (i = 0; i < numPerChild; i ++) {
                        childSum += data[count+i];
                    }
                }
            }
            close(fd[0]);
            write(fd[1], &childSum, sizeof(int));
            exit(0);
        }
        else if (pid > 0) {
            if (remainder == 0) {
                count += numPerChild;
            }
            else {
                if (childCount < remainder) {
                    count += (numPerChild + 1);
                }
                else {
                    count += numPerChild;
                }
            }
            childCount ++;

            close(fd[1]);
            read(fd[0], &sum, sizeof(int));
            totalSum += sum;
        }
    }

    /*print result to screen*/
    printf("Sum: %d\n", totalSum);

    /*wait for all child process to finish*/
    for (i = 0; i < childNum; i ++) {
        wait(NULL);
    }

    return 0;
}