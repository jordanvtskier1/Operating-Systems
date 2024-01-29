#define MAX_NAME_LENGTH 63
typedef struct {
    char name[1+MAX_NAME_LENGTH];
    unsigned int value;
    unsigned int weight;
} Collectible;

Collectible *createCollectible(char *name, unsigned int value, unsigned int weight);

int compareCollectibles(Collectible *collectibleOne, Collectible *collectibleTwo);


Collectible **buildCollectibleArray(unsigned int numItems,
unsigned int *values,
unsigned int *weights);


//int compareCollectiblesWrapper(Collectible **c1p, Collectible **c2p);
int compareCollectiblesWrapper(const void *c1p, const void *c2p);