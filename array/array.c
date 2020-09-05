/**
 * 实现一个支持动态扩容的数组
 * 实现一个大小固定的有序数组，支持动态增删改操作
 * 实现两个有序数组合并为一个有序数组
 */

#include <stdio.h>
#include <stdlib.h>

#include "array.h"

// construct
Array *newArray(int size)
{
    Array *arr = (Array *)malloc(sizeof(Array));
    if (size < 1)
        size = 8;
    int *a = (int *)malloc(sizeof(int) * size);
    arr->a = a;
    arr->size = size;
    arr->cur = 0;
    return arr;
}

void expand(Array *arr)
{
    int oldSize = arr->size;
    int *a = (int *)malloc(sizeof(int) * oldSize * 2);
    for (int i = 0; i < arr->cur; i++)
    {
        a[i] = arr->a[i];
    }
    free(arr->a);
    arr->a = a;
    arr->size = oldSize * 2;
}
void resize_f(Array *arr)
{
    int oldSize = arr->size;
    int *a = (int *)malloc(sizeof(int) * oldSize / 2);
    for (int i = 0; i < arr->cur; i++)
    {
        a[i] = arr->a[i];
    }
    free(arr->a);
    arr->a = a;
    arr->size = oldSize / 2;
}

// CRUD
void append(Array *arr, int ele)
{
    if (arr->cur >= arr->size)
    {
        expand(arr);
    }
    arr->a[arr->cur++] = ele;
}
void removeFn(Array *arr, int index)
{
    if (index >= arr->cur)
        return;

    for (int i = index; i < arr->cur - 1; i++)
    {
        arr->a[i] = arr->a[i + 1];
    }
    arr->cur--;

    if (arr->cur < arr->size / 4)
        resize_f(arr);
}
int get(Array *arr, int index)
{
    if (index >= arr->cur)
        return -1;
    return arr->a[index];
}

void set(Array *arr, int index, int number)
{
    if (index >= arr->cur)
        return;
    arr->a[index] = number;
}

int getSize(Array *arr)
{
    return arr->size;
}
void printAll(Array *arr)
{
    printf("[ ");
    for (int i = 0; i < arr->cur; i++)
    {
        if (i == arr->cur - 1)
        {
            printf("%d", arr->a[i]);
            break;
        }
        printf("%d, ", arr->a[i]);
    }
    printf(" ]\n");
}

// construct
SortedArr *newSortedArr(int size)
{
    SortedArr *arr = (SortedArr *)malloc(sizeof(SortedArr));
    if (size < 1)
        size = 8;
    int *a = (int *)malloc(sizeof(int) * size);
    arr->a = a;
    arr->size = size;
    arr->cur = 0;
    return arr;
}

// CRUD
void sappend(SortedArr *arr, int ele)
{
    if (arr->size == arr->cur)
        return;

    if (arr->cur == 0)
    {
        arr->a[arr->cur++] = ele;
        return;
    }

    int insert;
    for (insert = 0; insert < arr->cur; insert++)
        if (arr->a[insert] > ele)
            break;
    for (int i = arr->cur; i > insert; i--)
    {
        arr->a[i] = arr->a[i - 1];
    }
    arr->a[insert] = ele;
    arr->cur++;
}
void sremoveFn(SortedArr *arr, int index)
{
    if (index >= arr->cur)
        return;

    for (int i = index; i < arr->cur - 1; i++)
    {
        arr->a[i] = arr->a[i + 1];
    }
    arr->cur--;
}

void sprintAll(SortedArr *arr)
{
    printf("[ ");
    for (int i = 0; i < arr->cur; i++)
    {
        if (i == arr->cur - 1)
        {
            printf("%d", arr->a[i]);
            break;
        }
        printf("%d, ", arr->a[i]);
    }
    printf(" ]\n");
}

void combine(int *arr1, int N1, int *arr2, int N2, int *result)
{
    int N = N1 + N2;

    int i, j, k;
    for (i = 0, j = 0, k = 0; i < N1 && j < N2;)
    {
        if (arr1[i] < arr2[j])
        {
            result[k++] = arr1[i++];
        }
        else
        {
            result[k++] = arr2[j++];
        }
    }
    while (i < N1)
    {
        result[k++] = arr1[i++];
    }
    while (j < N2)
    {
        result[k++] = arr2[j++];
    }
}