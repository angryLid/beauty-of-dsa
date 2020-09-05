#include <stdio.h>
#include "sort.h"

int main(int argc, char const *argv[])
{
    int n[9] = {3, 5, 13, 1, 2, 5, 6, 79, 7};
    int m[] = {2, 34, 13, 54, 63, 12, 64, 23, 124, 545, 32};
    merge_sort(n, 9);
    mergeSort(m, 11);
    for (int i = 0; i < 9; i++)
    {
        printf("nums[%d] - %d\n", i, n[i]);
    }
    for (int i = 0; i < 11; i++)
    {
        printf("nums[%d] - %d\n", i, m[i]);
    }
    return 0;
}
