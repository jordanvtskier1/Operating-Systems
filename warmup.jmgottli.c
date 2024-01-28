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

}
;

int main(){
    char name[] = "Jordan";
    Collectible *test = createCollectible(name, 10, 12);

    printf("Name: %s\nValue: %u\nWeight: %u\n", test->name, test->value, test->weight);
    printf("Test");


    return 0;
    


}
;


