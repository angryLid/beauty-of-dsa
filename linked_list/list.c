#include <stdio.h>
#include <stdlib.h>
#include "list.h"
SingleList *createList()
{
    SingleList *ptr = (SingleList *)malloc(sizeof(SingleList));
    ptr->head = NULL;
    ptr->tail = NULL;
    ptr->length = 0;
    return ptr;
}

void freeList(SingleList *list)
{
    if (list == NULL)
        return;

    if (list->head == NULL)
    {

        free(list);
        return;
    }

    Node *p, *q = NULL;
    for (p = list->head; p; p = q)
    {
        q = p->next;
        free(p);
    }

    free(list);
}

void appendNode(SingleList *pList, int value)
{
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = value;
    p->next = NULL;

    if (pList->head == NULL)
    {
        pList->head = pList->tail = p;
    }
    else
    {
        pList->tail->next = p;
        pList->tail = p;
    }
    pList->length += 1;
}

void removeLastNode(SingleList *pList)
{
    if (pList->tail == NULL)
    {
        return;
    }
    if (pList->head == pList->tail)
    {
        pList->head = pList->tail = NULL;
        pList->length -= 1;
        return;
    }

    Node *p = pList->head;
    while (p->next != pList->tail)
        p = p->next;

    free(pList->tail);
    p->next = NULL;
    pList->length -= 1;
    pList->tail = p;
}

// 在指定位置插入一个结点，下标从 0 开始
void insertNodeAtIndex(SingleList *pList, int index, int value)
{
    if (index >= pList->length || index < 0)
    {
        // 下标越界
        printf("下标不合法!!!");
        return;
    }

    // 制造一个结点，加入链表中去
    Node *s = (Node *)malloc(sizeof(Node));
    s->value = value;
    s->next = NULL;

    Node *p = pList->head;
    Node *q = NULL;

    for (int i = 0; i < pList->length; i++)
    {
        // 找到了要插入的节点位置
        if (i == index)
        {
            if (i == 0)
            {
                // 插入到头结点
                s->next = pList->head;
                pList->head = s;
            }
            else
            {
                s->next = p;
                q->next = s;
            }

            pList->length += 1;
            break;
        }

        q = p;
        p = p->next;
    }
}

// 在指定位置删除一个结点
void deleteNodeAtIndex(SingleList *pList, int index)
{
    if (index >= pList->length || index < 0)
    {
        // 下标越界
        printf("下标不合法!!!");
        return;
    }

    Node *p = pList->head;
    Node *q = NULL;
    for (int i = 0; i < pList->length; i++)
    {
        if (index == i)
        {
            if (i == 0)
            {
                // 首节点，将链表的首节点指向
                pList->head = p->next;
            }
            else
            {
                q->next = p->next;
            }

            free(p);
            pList->length -= 1;
            break;
        }

        // 用 q 来记录 p 的上一个结点
        q = p;
        p = p->next;
    }
}

void printList(SingleList *pList)
{
    Node *p = pList->head;
    if (p == NULL)
    {
        printf("链表为空!!!");
    }
    while (p)
    {
        printf("%d\n", p->value);
        p = p->next;
    }
}