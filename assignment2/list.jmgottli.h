//
// Created by jorda on 2/8/2024.
//

#ifndef ASSIGNMENT2_LIST_JMGOTTLI_H
#define ASSIGNMENT2_LIST_JMGOTTLI_H

#define MAX_NAME_LENGTH 63
typedef struct {
    char name[1+MAX_NAME_LENGTH];
    unsigned int weight;
    unsigned int value;
} Collectible;

typedef struct ListNodeStruct{
    void *data;
    struct ListNodeStruct *next;
} ListNode;

int compareValues(void *v1, void *v2);

int compareNames(void *v1, void *v2);

void printCollectible(void *v);

int insertItem(ListNode **theList, void *data, int (comparisonFunction)(void *, void *));

void *findItem(ListNode *theList, void *name, int (comparisonFunction)(void *, void *));

int deleteItem(ListNode **theList, void *name, int (comparisonFunction)(void *, void *));

int printList(ListNode *theList, void (printFunction)(void *));


#endif //ASSIGNMENT2_LIST_JMGOTTLI_H
