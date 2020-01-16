/**************************************************************************
 * file:               tSum.c
 * author:             Yufan Xu
 * assignment:         project 9
 * description:        this program uses multiple threads to sum numbers
 *                     found in a file
 * date created:       11/27/2018
 * date last modified: 11/27/2018
 * date due:           11/27/2018
 *************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pthread.h>
#include <semaphore.h>

int numPerThread = 0;
int part = 0;
int sum[] = {0};
int a[] = {0};
int rem;
int C;

sem_t memLock;

/*funtion calculates the sum of each thread*/
void* sum_thread(void* arg)
{
    int thread_part = part++;
    printf("npt: %d\n", numPerThread);

    int i;
    if (thread_part == 0) {
        for (i = thread_part * numPerThread; i < (thread_part + 1) * numPerThread; i++) {
            /*lock semaphore*/
            sem_wait(&memLock);
            sum[thread_part] += a[i];

            /*release semaphore*/
            sem_post(&memLock);
        }
    } else {
        for (i = thread_part * numPerThread; i < (thread_part + 1) * numPerThread - 1; i++) {
            /*lock semaphore*/
            sem_wait(&memLock);
            sum[thread_part] += a[i];

            /*lock semaphore*/
            sem_post(&memLock);
        }
    }

    printf("this sum: %d\n", sum[thread_part]);

    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int intNum, i, remainder, threadNum;
    FILE *fp;
    int *data, totalSum = 0;

    struct stat fileInfo;

    /*check for valid command line input*/
    if (argc != 3) {
        perror("Wrong number of inputs\n");
        exit(1);
    }

    /*get the number child process*/
    threadNum = atoi(argv[2]);

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

    /*create a buffer to read*/
    data = (int *) malloc(sizeof(int) * intNum);

    int val;

    for (i = 0; i < intNum; i ++) {
        fread(&val, sizeof(int), 1, fp);
        data[i] = val;
    }

    for (i = 0; i < intNum; i ++) {
        a[i] = data[i];
    }

    /*assign numbers to each child*/
    numPerThread = intNum / threadNum;
    remainder = intNum % threadNum;
    //rem = remainder;

    pthread_t threads[threadNum];

    /*create multiple threads*/
    for (i = 0; i < threadNum; i++) {
        if (pthread_create(&threads[i], NULL, sum_thread, NULL) != 0) {
            perror("Failed");
            return 1;
        }
    }

    sleep(2);

    /*wait for each thread to complete*/
    for (i = 0; i < threadNum; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Bad");
            return 1;
        }
    }

    /*calculate total sum of each thread*/
    for (i = 0; i < threadNum; i++) {
        totalSum += sum[i];
    }

    /*destroy semaphore*/
    sem_destroy(&memLock);

    /*print result to screen*/
    printf("Sum: %d\n", totalSum);

    return 0;
}