#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main(int argc, char const *argv[])
{
    printf("function single_list_test\n");
    SingleList *pList = createList();
    // 加入结点
    printf("------加入结点\n");
    appendNode(pList, 10);
    appendNode(pList, 20);
    appendNode(pList, 30);
    appendNode(pList, 40);
    appendNode(pList, 50);

    printList(pList);

    printf("------删除结点\n");
    removeLastNode(pList);
    printList(pList);

    printf("------插入新结点到头结点位置\n");
    insertNodeAtIndex(pList, 0, 100);
    printList(pList);

    printf("------插入新结点到尾结点位置\n");
    insertNodeAtIndex(pList, 4, 200);
    printList(pList);

    printf("------插入新结点到中间结点位置\n");
    insertNodeAtIndex(pList, 1, 300);
    printList(pList);

    printf("------插入新结点到中间结点位置\n");
    insertNodeAtIndex(pList, 3, 500);
    printList(pList);

    printf("------删除头结点\n");
    deleteNodeAtIndex(pList, 0);
    printList(pList);

    printf("------删除尾结点\n");
    deleteNodeAtIndex(pList, 6);
    printList(pList);

    printf("------删除中间结点\n");
    deleteNodeAtIndex(pList, 3);
    printList(pList);

    printf("------删除中间结点\n");
    deleteNodeAtIndex(pList, 2);
    printList(pList);

    // 释放链表
    freeList(pList);
    return 0;
}
