#define MAX_NAME_LENGTH 63
typedef struct {
    char name[1+MAX_NAME_LENGTH];
    unsigned int value;
    unsigned int weight;
} Collectible;
