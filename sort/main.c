#include <stdio.h>
#include "sort.h"

void test(int *nums, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", nums[i]);
    }
    printf("]\n");
}
int main(int argc, char const *argv[])
{
    printf("bubble\n");
    int test1[] = {3, 5, 13, 1, 2, 5, 6, 79, 7};
    int test2[] = {2, 34, 13, 54, 63, 12, 64, 23, 124, 545, 32};
    bubble_sort(test1, 9);
    bubble_sort(test2, 11);
    test(test1, 9);
    test(test2, 11);

    printf("insertion\n");
    int insertion[] = {3, 5, 13, 1, 2, 5, 6, 79, 7};
    int insertion2[] = {2, 34, 13, 54, 63, 12, 64, 23, 124, 545, 32};
    insertion_sort(insertion, 9);
    insertion_sort(insertion2, 11);
    test(insertion, 9);
    test(insertion2, 11);

    printf("selection\n");
    int selection[] = {3, 5, 13, 1, 2, 5, 6, 79, 7};
    int selection2[] = {2, 34, 13, 54, 63, 12, 64, 23, 124, 545, 32};
    selection_sort(selection, 9);
    selection_sort(selection2, 11);
    test(selection, 9);
    test(selection2, 11);

    printf("merge\n");
    int m[] = {3, 5, 13, 1, 2, 5, 6, 79, 7};
    int m2[] = {2, 34, 13, 54, 63, 12, 64, 23, 124, 545, 32};
    int test00[] = {3, 0, 1, 9, -1, 4};
    int test01[] = {432, 1, 9, 4, 2, 42, 57, 43, 342, 435};
    merge_sort(m, 9);
    merge_sort(m2, 11);
    merge_sort(test00, 6);
    merge_sort(test01, 10);
    test(m, 9);
    test(m2, 11);
    test(test00, 6);
    test(test01, 10);

    printf("merge\n");
    int mm[] = {3, 5, 13, 1, 2, 5, 6, 79, 7};
    int mm2[] = {2, 34, 13, 54, 63, 12, 64, 23, 124, 545, 32};
   int test10[] = {3, 0, 1, 9, -1, 4};
    int test11[] = {432, 1, 9, 4, 2, 42, 57, 43, 342, 435};
    merge_sort(m, 9);
    merge_sort(m2, 11);
    merge_sort(test10, 6);
    merge_sort(test11, 10);
    test(m, 9);
    test(m2, 11);
    test(test10, 6);
    test(test11, 10);
    return 0;
}
