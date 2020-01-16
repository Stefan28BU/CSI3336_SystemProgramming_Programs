/****************************************************************************
 * filename:           fileInfo.c
 * author:             Yufan Xu
 * assignment:         Project 6 - fileInfo
 * description:        This program allows the user to pass arguments through
 *                     command line, it will sort the files using 4 different
 *                     sorting methods, based on the size of the file, the
 *                     access time, the modified time, the status change time
 *                     of the file.
 * date created:       10/08/2018
 * date last modified: 10/09/2018
 * date due:           10/09/2018
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

struct FileInfo {
    char *path;
    struct stat info;
} ;

typedef struct Node {
    struct FileInfo file;
    struct Node *next;
}Node;

/*******************************************************
 * description: swap node1 and node2
 * return: void
 * precondition: both node exists
 * postcondition: node1's data and node2's data swapped
 ******************************************************/
void swap(Node *node1, Node *node2){
    char *tempPath;
    struct stat tempInfo;

    tempPath = node1->file.path;
    tempInfo = node1->file.info;

    node1->file.path = node2->file.path;
    node1->file.info = node2->file.info;

    node2->file.path = tempPath;
    node2->file.info = tempInfo;
}

/*******************************************************
 * description: insert a node at front of the list
 * return: void
 * precondition: head exists
 * postcondition: new node is added to the head
 ******************************************************/
void insertAtHead(Node **head, char *p) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->file.path = p;
    stat(p, &(node->file.info));

    node->next = (*head);
    (*head) = node;
}

/*******************************************************
 * description: delete the list
 * return: void
 * precondition: list exists
 * postcondition: list is freed
 ******************************************************/
void deleteList(Node **head) {
    Node *temp = *head;
    Node *next;
    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    (*head) = NULL;
}

/*******************************************************
 * description: sort by size of files
 * return: void
 * precondition: nodePtr exists
 * postcondition: list is sorted
 ******************************************************/
void sortBySize(Node *nodePtr) {
    int doSwap;
    Node *cmp = NULL;
    do {
        doSwap = 0;
        Node *temp = nodePtr;
        while (temp->next != cmp) {

            if (temp->file.info.st_size > temp->next->file.info.st_size) {
                swap(nodePtr, nodePtr->next);
                doSwap = 1;
            }
            temp = temp->next;
        }
        cmp = temp;
    } while (doSwap == 1);
}

/*******************************************************
 * description: sort by Access Time
 * return: void
 * precondition: nodePtr exists
 * postcondition: list is sorted
 ******************************************************/
void sortByAccessTime(Node *nodePtr) {
    int doSwap;
    Node *cmp = NULL;
    do {
        doSwap = 0;
        Node *temp = nodePtr;
        while (temp->next != cmp) {
            if (temp->file.info.st_atime > temp->next->file.info.st_atime) {
                swap(nodePtr, nodePtr->next);
                doSwap = 1;
            }
            temp = temp->next;
        }
        cmp = temp;
    } while (doSwap == 1);
}

/*******************************************************
 * description: sort by Modified Time
 * return: void
 * precondition: nodePtr exists
 * postcondition: list is sorted
 ******************************************************/
void sortByMofidiedTime(Node *nodePtr) {
    int doSwap;
    Node *cmp = NULL;
    do {
        doSwap = 0;
        Node *temp = nodePtr;
        while (temp->next != cmp) {
            if (temp->file.info.st_mtime > temp->next->file.info.st_mtime) {
                swap(nodePtr, nodePtr->next);
                doSwap = 1;
            }
            temp = temp->next;
        }
        cmp = temp;
    } while (doSwap == 1);
}

/*******************************************************
 * description: sort by Status Change Time
 * return: void
 * precondition: nodePtr exists
 * postcondition: list is sorted
 ******************************************************/
void sortByStatusChangeTime(Node *nodePtr) {
    int doSwap;
    Node *cmp = NULL;
    do {
        doSwap = 0;
        Node *temp = nodePtr;
        while (temp->next != cmp) {
            if (temp->file.info.st_ctime > temp->next->file.info.st_ctime) {
                swap(nodePtr, nodePtr->next);
                doSwap = 1;
            }
            temp = temp->next;
        }
        cmp = temp;
    } while (doSwap == 1);
}

/*main function*/
int main(int argc, char *argv[]) {
    int i;
    Node *head = NULL;

    insertAtHead(&head, argv[1]);
    for (i = 1; i < argc; i ++){
        insertAtHead(&head, argv[i]);
    }

    /*display menu*/
    printf("Choose your order:\n");
    printf("1. by size:\n");
    printf("2. by access time:\n");
    printf("3. by modified time:\n");
    printf("4. by status change time:\n");

    /*read input*/
    int input;
    scanf("%d", &input);

    /*echo print*/
    printf(": %d\n", input);

    /*determine which mode and sort*/
    if (input == 1) {
        sortBySize(head);
    }
    else if (input == 2) {
        sortByAccessTime(head);
    }
    else if (input == 3) {
        sortByMofidiedTime(head);
    }
    else if (input == 4) {
        sortByStatusChangeTime(head);
    }

    /*display result*/
    Node *nodePtr = head;
    while (nodePtr->next) {
        printf("%s ", nodePtr->file.path);
        nodePtr = nodePtr->next;
    }
    printf("\n");

    /*free memory*/
    deleteList(&head);

    return 0;
}

