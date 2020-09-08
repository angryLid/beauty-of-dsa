/**
 * http://www.jeepxie.net/article/802621.html
 */
#include <stdio.h>
#include <stdlib.h>

#include "hashmap.h"
#include "lru.h"

#define HM_CAP 53
int main()
{
    // TestHashTableBucket();
    // system("pause");
    /*  List *list = newList(4);
    Node *n1 = insertNode(list, 1, 1000);
    Node *n2 = insertNode(list, 2, 2000);
    Node *n3 = insertNode(list, 3, 3000);
    Node *n4 = insertNode(list, 4, 4000);
    Node *n5 = insertNode(list, 5, 5000);
    Node *n6 = insertNode(list, 6, 6000);
    listToString(list);
    activateNode(list, n3);
    listToString(list);
    activateNode(list, n4);
    listToString(list);
    activateNode(list, n6);
    listToString(list);
    activateNode(list, n5);
    listToString(list);
    n1 = insertNode(list,7,7000);
    listToString(list);
    activateNode(list,n6);
    listToString(list); */

    HashMap *hashmap = newHashMap(HM_CAP);
    List *list = newList(4);
    HMPut(hashmap, list, 1, 1000);
    HMPut(hashmap, list, 2, 2000);
    HMPut(hashmap, list, 3, 3000);
    HMPut(hashmap, list, 4, 4000);
    HMPut(hashmap, list, 5, 5000);
    listToString(list);
    int value = 0;
    int result = keyExist(hashmap, list, 1, &value);
    printf("result: %d, value: %d\n", result, value);
    result = keyExist(hashmap,list,3,&value);
    printf("result: %d, value: %d\n", result, value);
    listToString(list);
    // keyExist(hashmap, 2);
    return 0;
}