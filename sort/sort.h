#ifndef SORT_H_
#define SORT_H_

void bubble_sort(int *nums, int numsSize);
void insertion_sort(int *nums, int numsSize);
void selection_sort(int *nums, int numsSize);

void merge_sort(int *nums, int numsSize);
void mergeSort(int *nums, int numsSize);
void mSort(int *nums, int *tmp, int numsSize, int length);
void merge(int *nums, int *tmp, int left, int mid, int right);
void m_sort(int *nums, int *tmp, int left, int right);
#endif /* SORT_H_ */