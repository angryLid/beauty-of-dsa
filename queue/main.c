#include <stdio.h>
#include <stdlib.h>

#define $ *

int main()
{
    int i = 2;
    int $ ptr = &i;
    printf("%p %d", ptr, *ptr);
    return 0;
}