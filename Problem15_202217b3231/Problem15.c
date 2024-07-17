#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char *key;
    char *value;
    struct node *next;
};

struct hashMap{
    int numOfElements, capacity;
    struct node **arr;
};

void setNode(struct node *node, char *key, char *value){
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
}

void initializeHashMap(struct hashMap *mp){
    mp->capacity = 100;
    mp->numOfElements = 0;
    mp->arr = (struct node **)malloc(sizeof(struct node *) * mp->capacity);

    for (int i=0; i<mp->capacity; ++i){
        mp->arr[i] = NULL;
    }
}

int hashFunction(struct hashMap *mp, char *key){
    unsigned long hash = 5381;
    int c;

    while((c = *key++)){
    hash = ((hash << 5) + hash ) + c;
    }

    return hash % mp->capacity;
}

void insert(struct hashMap *mp, char *key, char *value){
    int bucketIndex = hashFunction(mp, key);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    setNode(newNode, key, value);

    if (mp->arr[bucketIndex] == NULL)
        mp->arr[bucketIndex] = newNode;
    else {
        newNode->next = mp->arr[bucketIndex];
        mp->arr[bucketIndex] = newNode;
    }
    mp->numOfElements++;
}

void delete(struct hashMap *mp, char *key){
    int bucketIndex = hashFunction(mp, key);

    struct node *prevNode = NULL;
    struct node *currNode = mp->arr[bucketIndex];

    while(currNode != NULL){
        if (strcmp(key, currNode->key) == 0){
            if (prevNode == NULL){
                mp->arr[bucketIndex] = currNode->next;
            }
            else
                prevNode->next = currNode->next;

            free(currNode->key);
            free(currNode->value);
            free(currNode);

            mp->numOfElements--;
            return;
        }

        prevNode = currNode;
        currNode = currNode->next;
    }
}

char *search(struct hashMap *mp, char *key){
    int bucketIndex = hashFunction(mp, key);

    struct node *bucketHead = mp->arr[bucketIndex];

    while(bucketHead != NULL){
        if (strcmp(bucketHead->key, key) == 0)
            return bucketHead->value;

        bucketHead = bucketHead->next;
    }

    return "Oops! No DATA found.\n";
}

int main(){
    struct hashMap *mp = (struct hashMap *)malloc(sizeof(struct hashMap));

    initializeHashMap(mp);

    insert(mp, "Yogaholic", "Anjali");
    insert(mp, "pluto14", "Vartika");
    insert(mp, "elite_programmer", "Manish");
    insert(mp, "GFG", "BITS");
    insert(mp, "decentBoy", "Mayank");

    printf("%s\n", search(mp, "elite_programmer"));
    printf("%s\n", search(mp, "Yogaholic"));
    printf("%s\n", search(mp, "pluto14"));
    printf("%s\n", search(mp, "decentBoy"));
    printf("%s\n", search(mp, "GFG"));

    printf("%s\n", search(mp, "aergzvwgc"));

    delete(mp, "decentBoy");

    printf("\nAfter deletion:\n");
    printf("%s\n", search(mp, "decentBoy"));

    return 0;
}
