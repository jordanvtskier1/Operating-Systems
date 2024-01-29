#include "warmup.jmgottli.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

Collectible *createCollectible(char *name, unsigned int value, unsigned int weight){
    if (name == NULL || strlen(name) == 0 || strlen(name) > MAX_NAME_LENGTH) {
        return NULL;
    }

    if (value <= 0 || weight <= 0){
        return NULL;
    }

    Collectible *rec = malloc(sizeof(Collectible));

    if (rec == NULL){
        return NULL;
    }

    //free(rec); I'm not really sure when to use this I just know it said we should in the lecture

    strcpy(rec ->name,name);
    rec ->value = value;
    rec ->weight = weight;

    return rec;

};

int compareCollectibles(Collectible *collectibleOne, Collectible *collectibleTwo){
    if (collectibleOne->value < collectibleTwo->value){
        return -1;
    }

    if (collectibleOne->value > collectibleTwo->value){
        return 1;
    }

    else {
        int result = strcmp(collectibleOne->name, collectibleTwo->name);
        if (result == 0){
            return 0;
        }

        if (result > 0){
            return 1;
        }

        else {
            return 0;
        }
    }
};


Collectible **buildCollectibleArray(unsigned int numItems, unsigned int *values, unsigned int *weights){
    char name[MAX_NAME_LENGTH];
    Collectible **array = malloc(numItems * sizeof(Collectible *));
    for (unsigned int i = 0; i < numItems; i++){
        sprintf(name,"C%d", i);
        array[i]=createCollectible(name, values[i],weights[i]);
    }

    return array;

}


int compareCollectiblesWrapper(const void *c1p, const void *c2p) {
    // this was extremely confusing to create since it doesn't match the function from the assignment,
    // but it makes sense after looking up the requirements for a qsort comparator
    Collectible *c1 = *(Collectible **)c1p;
    Collectible *c2 = *(Collectible **)c2p;

    return compareCollectibles(c1, c2);
}



int main(){
    unsigned int values[] = {200, 100, 400, 300};
    unsigned int weights[] = {1,2,3,4};
    unsigned int numItems = sizeof(values)/sizeof(values[0]);

    Collectible **array = buildCollectibleArray(numItems, values, weights);

    printf("Array before sorting:\n");
    for (unsigned int i = 0; i < numItems; ++i) {
        printf("Name: %s, Value: %u, Weight: %u\n", array[i]->name, array[i]->value, array[i]->weight);
    }
    
    qsort(array, numItems, sizeof(Collectible *), compareCollectiblesWrapper);

    printf("\nArray after sorting:\n");
    for (unsigned int i = 0; i < numItems; ++i) {
        printf("Name: %s, Value: %u, Weight: %u\n", array[i]->name, array[i]->value, array[i]->weight);
    }

    return 0;
    


};


