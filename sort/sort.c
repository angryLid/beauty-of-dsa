#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
#define min(a, b) (((a) < (b)) ? (a) : (b))
void bubble_sort(int *nums, int numsSize)

{
    if (numsSize < 2)
        return;
    for (int i = 0; i < numsSize; i++)
    {
        bool flag = false;
        for (int j = 0; j < numsSize - i - 1; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
                flag = true;
            }
        }
        if (!flag)
            return;
    }
}
// 插入排序 原地，稳定，平方
void insertion_sort(int *nums, int numsSize)
{
    if (numsSize < 2)
        return;
    for (int i = 1; i < numsSize; i++)
    {
        int j = i - 1;
        int value = nums[i];
        for (; j >= 0; j--)
        {
            if (nums[j] > value)
                nums[j + 1] = nums[j];
            else
                break;
        }
        nums[j + 1] = value;
    }
}

// 选择排序 原地，不稳定，平方
void selection_sort(int *nums, int numsSize)
{
    if (numsSize <= 1)
        return;

       for (int i = 0; i < numsSize; i++)
    {
        int minAt = i;
        for (int j = i; j < numsSize; j++)
            if (nums[j] < nums[minAt])
                minAt = j;

        int tmp = nums[minAt];
        nums[minAt] = nums[i];
        nums[i] = tmp;
    }
}

void mergeSort(int *nums, int numsSize)
{
    int *tmp = (int *)malloc(sizeof(int) * numsSize);
    int length = 1;
    while (length < numsSize)
    {
        mSort(nums, tmp, numsSize, length);
        length *= 2;
        // mSort(tmp, nums, numsSize, length);
        // length *= 2;
    }
    free(tmp);
    tmp = NULL;
}

void mSort(int *nums, int *tmp, int size, int len)
{
    int i;
    for (i = 0; i < size - 2 * len - 1; i += 2 * len)
    {
        merge(nums, tmp, i, i + len - 1, i + 2 * len - 1);
    }
    if (i < size - len + 1)
        merge(nums, tmp, i, i + len - 1, size - 1);
}

void merge_sort(int *nums, int numsSize)
{
    int *tmp = (int *)malloc(sizeof(int) * numsSize);
    m_sort(nums, tmp, 0, numsSize - 1);
    free(tmp);
    tmp = NULL;
}

void m_sort(int *nums, int *tmp, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        m_sort(nums, tmp, left, mid);
        m_sort(nums, tmp, mid + 1, right);
        merge(nums, tmp, left, mid, right);
    }
}

void merge(int *nums, int *tmp, int left, int mid, int right)
{

    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right)
    {
        if (nums[i] < nums[j])
        {
            tmp[t++] = nums[i++];
        }
        else
        {
            tmp[t++] = nums[j++];
        }
    }
    while (i <= mid)
        tmp[t++] = nums[i++];
    while (j <= right)
        tmp[t++] = nums[j++];

    t = 0;
    while (left <= right)
        nums[left++] = tmp[t++];
}