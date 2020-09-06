#include <stdio.h>
#include <stdlib.h>
#include "search.h"

int main(int argc, char const *argv[])
{
    int test0[] = {1, 2, 4, 5, 7, 8, 9, 11, 12, 14, 16, 17};
    binarySearch(test0, 17, 30);
    binarySearch(test0, 17, 6);
    binarySearch(test0, 17, -2);
    bSearch(test0, 17, 14);
    return 0;
}
