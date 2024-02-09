//
// Created by jorda on 2/8/2024.
//
#include "list.jmgottli.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// I finally figured out how to use gdb, wow its useful
// CLion refused to build my code which is very annoying
// It's a very good IDE for writing it though


int compareValues(void *v1, void *v2) {
    Collectible *c1 = (Collectible *)v1;
    Collectible  *c2 = (Collectible *)v2;

    if (c1->value < c2->value){
        return -1;
    }

    if (c1->value > c2->value){
        return 1;
    }

    else {
        return 0;
    }
}

int compareNames(void *v1, void *v2){
    char *charPtr = (char *)v1;
    Collectible *c1 = (Collectible *)v2;

    int result = strcmp(c1->name,charPtr);
    if (result == 0){
        return 1;
    } else {
        return 0;
    }
}

void printCollectible(void *v){
    Collectible *c1 = (Collectible *)v;
    printf("%s: v=%d, w=%d\n",c1->name,c1->value,c1->weight);
}

int insertItem(ListNode **theList, void *data, int (comparisonFunction)(void *, void*)){
    ListNode *curr = *theList;
    ListNode  *prev = NULL;

    ListNode *newNode = malloc(sizeof(ListNode));
    if (newNode == NULL){
        return -99;
    }

    newNode->data = data;
    newNode->next = NULL;

    // empty list or lowest value
    if (curr == NULL || comparisonFunction(data, curr->data) <= 0){
        newNode->next = *theList;
        *theList = newNode;
    } else{
        while (curr != NULL && comparisonFunction(data, curr->data) > 0) {
            prev = curr;
            curr = curr->next;
        }

        newNode->next = curr;
        if(prev != NULL){
            prev->next = newNode;
        } else {
            newNode->next = *theList; //redundant I think because of first if statement
            *theList = newNode;
        }
    }
    return 0;
}

void *findItem(ListNode *theList, void *name, int (comparisonFunction)(void *, void *)){
    ListNode *curr = theList;

    while (curr != NULL) {
        // I had a bug that took me hours to figure out.
        // I had my v1 and v2 swapped so I was passing the wrong data to compareNames
        if (comparisonFunction(name,curr->data)!=0){
            return curr->data;
        } else {
            curr = curr->next;
        }
    }
    return NULL;
}


int deleteItem(ListNode **theList, void *name, int (comparisonFunction)(void *, void *)){
    ListNode *curr = *theList;
    ListNode *prev = NULL;

    while (curr != NULL && comparisonFunction(curr->data,name) != 1){
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL){
        return 1;
    } else {
        if (prev != NULL){
            prev->next = curr->next;
        } else{
            *theList = curr->next;
        }
        free(curr);
        return 0;
    }
}

int printList(ListNode *theList, void (printFunction)(void *)){
    ListNode *curr = theList;
    while(curr != NULL){
        printFunction(curr->data);
        curr = curr->next;
    }
    return 0;
}






