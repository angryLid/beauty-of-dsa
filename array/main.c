#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char const *argv[])
{
    printf("Start testing dynamic array\n");
    Array *arr0 = newArray(16);
    append(arr0, 1);
    append(arr0, 22);
    append(arr0, 333);
    printf("%d\n", getSize(arr0));
    removeFn(arr0, 0);
    printf("%d\n", getSize(arr0));
    printf("%d\n", get(arr0, 0));
    printAll(arr0);
    append(arr0, 1);
    append(arr0, 22);
    append(arr0, 333);
    append(arr0, 4444);
    append(arr0, 5);
    append(arr0, 6);
    append(arr0, 7);
    printAll(arr0);
    removeFn(arr0, 6);
    printAll(arr0);
    removeFn(arr0, 5);
    printAll(arr0);
    set(arr0, 0, 2233);
    printf("\n%d %d\n", get(arr0, 0), getSize(arr0));
    printf("%d\n", getSize(arr0));

    printf("Start testing sorted arr...\n");
    SortedArr *arr = newSortedArr(16);
    sappend(arr, 3);
    sappend(arr, 7);
    sappend(arr, 5);
    sappend(arr, 4);
    sappend(arr, 1);
    sappend(arr, 8);
    sappend(arr, 6);
    sappend(arr, 9);
    sappend(arr, 0);
    sappend(arr, 2);
    sprintAll(arr);
    sremoveFn(arr, 3);
    sremoveFn(arr, 3);
    sremoveFn(arr, 3);
    sprintAll(arr);

    printf("Start testing function combine...\n");
    int arr1[] = {1, 3, 5, 7, 9};
    int arr2[] = {2, 4, 6, 8, 10, 11, 12, 13};
    int *result = (int *)malloc(sizeof(int) * 13);
    combine(arr1, 5, arr2, 8, result);
    for (int i = 0; i < 13; i++)
    {
        printf("%d\n", result[i]);
    }
    return 0;
}
