#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int binarySearch(int a[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midVal = a[mid];
        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
        {
            printf("found %d at %d\n", key, mid);
            return mid;
        }
    }
    printf("Not Found\n");
    return -1;
}
// 实现模糊二分查找算法（比如大于等于给定值的第一个元素）
int bSearch(int a[], int n, int key)
{
    // if (key > a[n - 1])
    // {
    //     return -1;
    // }
    int low = 0;
    int high = n - 1;
    int c = a[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midVal = a[mid];
        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
        {

            c = a[mid];
            high = mid - 1;
        }
    }
    printf("found %d \n", c);
    return c;
}
