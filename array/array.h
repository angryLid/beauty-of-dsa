#ifndef ARRAY_H
#define ARRAY_H
// dynamic array declaration
//typedef struct _array
//{
//    int* a;
//    int size;
//    int cur;
//} Array;
//typedef struct _sorted_array
//{
//    int* a;
//    int size;
//    int cur;
//} sortedarr;
struct _array
{
    int *a;
    int size;
    int cur;
};
typedef struct _array Array;
typedef struct _array SortedArr;
Array *newArray(int size);
void expand(Array *arr);
void resize_f(Array *arr);
void append(Array *arr, int ele);
void removeFn(Array *arr, int index);
int get(Array *arr, int index);
void set(Array *arr, int index, int number);
int getSize(Array *arr);
void printAll(Array *arr);

int dynamic_test();
// sorted array

SortedArr *newSortedArr(int size);
void sappend(SortedArr *arr, int ele);
void sremoveFn(SortedArr *arr, int index);
void sprintAll(SortedArr *arr);
int sorted_test();

// combine 2 sorted array
void combine(int *arr1, int N1, int *arr2, int N2, int *result);
int combine_test();
#endif // !ARRAY_H
