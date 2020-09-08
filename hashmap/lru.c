#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "lru.h"

// 假哈希函数
int hash(HashMap *h, int key)
{
    return key % h->capacity;
}
// 初始化一个双向链表
List *newList(int capacity)
{
    List *l = (List *)malloc(sizeof(List));
    l->capacity = capacity;
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
}
// 往表中插入一个新节点，如果超载，就移除头节点
Node *insertNode(List *list, int key, int value, int *removedKey)
{
    // Create a new Node
    Node *n = (Node *)malloc(sizeof(Node));
    n->prev = NULL;
    n->next = NULL;
    n->key = key;
    n->value = value;
    // if list is full
    if (list->size == list->capacity)
    {
        *removedKey = removeNode(list);
    }
    // size add 1 anyway
    list->size++;

    // if list contains no Node
    if (list->head == NULL)
    {
        list->head = n;
        list->tail = n;
        return n;
    }

    // insert Node into list
    n->prev = list->tail;
    list->tail->next = n;
    list->tail = n;

    return n;
}

// 移除头节点，返回头节点的key
int removeNode(List *list)
{

    Node *n = list->head;
    int key = n->key;
    list->head = list->head->next;
    list->head->prev = NULL;
    free(n);
    n = NULL;
    list->size--;
    return key;
}

// 激活一个节点，移动到链表的尾部
void activateNode(List *list, Node *node)
{
    if (node == list->tail)
    {
        printf("Debug: this is tail node\n");
        return;
    }

    if (node == list->head)
    {
        printf("DEBUG: this is head node\n");

        list->tail->next = node;
        node->prev = list->tail;
        list->head = list->head->next;
        list->head->prev = NULL;
        node->next = NULL;
        list->tail = node;
        return;
    }
    printf("DEBUG: this is middle node\n");
    Node *left = node->prev;
    Node *right = node->next;
    left->next = right;
    right->prev = left;
    node->prev = list->tail;
    list->tail->next = node;
    node->next = NULL;
    list->tail = node;
}
// 打印双向链表
void listToString(List *list)
{
    Node *curr = list->head;
    while (curr != NULL)
    {
        printf("Address:%p, key:%d, value:%d\n", curr, curr->key, curr->value);
        curr = curr->next;
    }
}
// 初始化哈希表
HashMap *newHashMap(int capacity)
{
    HashMap *h = (HashMap *)malloc(sizeof(HashMap));
    Ele *e = (Ele *)calloc(capacity, sizeof(Ele));
    h->a = e;
    h->capacity = capacity;
    memset(h->a, 0, sizeof(Ele) * capacity);
    return h;
}

// 哈希表新增对象
void HMPut(HashMap *hashmap, List *list, int key, int value)
{
    int rmKey = -1;
    Node *node = insertNode(list, key, value, &rmKey);
    if (rmKey > -1)
    {
        HMRemove(hashmap, rmKey);
    }
    int index = hash(hashmap, key);
    hashmap->a[index].key = key;
    hashmap->a[index].address = node;
}

// 哈希表移除对象
void HMRemove(HashMap *hashmap, int key)
{
    int index = hash(hashmap, key);
    hashmap->a[index].address = NULL;
    hashmap->a[index].key = -1;
}

// 检测Key是否已经存在，若存在则激活并取value
int keyExist(HashMap *hashmap, List *list, int key, int *value)
{
    int index = hash(hashmap, key);

    if (hashmap->a[index].key == key)
    {
        *value = hashmap->a[index].address->value;
        activateNode(list, hashmap->a[index].address);
        return 0;
    }

    else
        return -1;
}
