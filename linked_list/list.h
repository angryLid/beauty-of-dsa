#ifndef LIST_H
#define LIST_H

typedef struct _node
{
    int value;
    struct _node *next;
} Node;

// SList for SingleList
typedef struct
{
    Node *head;
    Node *tail;
    int length;
} SingleList;

SingleList *createList();

void freeList(SingleList *pList);

void appendNode(SingleList *pList, int value);

void removeLastNode(SingleList *pList);

void insertNodeAtIndex(SingleList *pList, int index, int value);

void deleteNodeAtIndex(SingleList *pList, int index);

void printList(SingleList *pList);

#endif /* LIST_H */