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

    //free(rec);

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

    if (collectibleOne->value = collectibleTwo->value){
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
}



int main(){
    char name[] = "Jordan";
    Collectible *test = createCollectible(name, 10, 12);

    printf("Name: %s\nValue: %u\nWeight: %u\n", test->name, test->value, test->weight);
    Collectible collectible1 = {"Diamond", 500, 2};
    Collectible collectible2 = {"Gold", 300, 3};
    Collectible collectible3 = {"Silver", 500, 4};

    int result1 = compareCollectibles(&collectible1, &collectible2);
    printf("Result 1: %d\n", result1);  // Expect 1

    int result2 = compareCollectibles(&collectible1, &collectible3);
    printf("Result 2: %d\n", result2);  // Expect 0

    int result3 = compareCollectibles(&collectible2, &collectible3);
    printf("Result 3: %d\n", result3);  // Expect -1

    printf("Test");


    return 0;
    


};


