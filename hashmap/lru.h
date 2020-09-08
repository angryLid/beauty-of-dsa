#ifndef LRU_H
#define LRU_H

typedef struct node
{
    int key;
    int value;
    struct node *next;
    struct node *prev;
} Node;

typedef struct list
{
    int size;
    int capacity;
    Node *head;
    Node *tail;
} List;

List *newList(int capacity);
Node *insertNode(List *list, int key, int value, int *removedKey);
void activateNode(List *list, Node *node);
void listToString(List *list);

typedef struct lru_element
{
    int key;
    struct node *address;
} Ele;

typedef struct hashmap
{
    Ele *a;
    int capacity;

} HashMap;

HashMap *newHashMap(int capacity);
void HMPut(HashMap *hashmap, List *list, int key, int value);
void HMRemove(HashMap *hashmap, int key);
int keyExist(HashMap *hashmap, List *list, int key, int *value);
int removeNode(List *list);
#endif /* LRU_H */
