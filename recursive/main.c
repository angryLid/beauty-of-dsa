/**
 * 编程实现斐波那契数列求值 f(n)=f(n-1)+f(n-2)
 * 编程实现求阶乘 n!
 * 编程实现一组数据集合的全排列
*/

#include <stdio.h>
#include <stdlib.h>

// Fibonacci
// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765
int fib(int n);
int fib_dp(int n);

//Factorial
int fac(int n);

//permutation
void per(int *nums, int cursor, int end);

int main()
{
    // int res = fib_dp(20);
    // printf("%d\n", res);
    // res = fac(6);
    // printf("%d\n", res);

    int nums[] = {1, 2, 3, 4};
    per(nums, 0, 3);
    return 0;
}

int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int fib_dp(int n)
{
    if (n == 1 || n == 2)
        return 1;

    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++)
    {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}

int fac(int n)
{
    if (n == 0)
        return 1;

    return n * fac(n - 1);
}

void toString(int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    printf("\n");
}
void swap(int *nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
void per(int *nums, int cursor, int end)
{
    if (cursor == end)
    {
        toString(nums, 4);
    }
    else
    {
        for (int i = cursor; i <= end; i++)
        {
            swap(nums, cursor, i);
            per(nums, cursor + 1, end);
            swap(nums, cursor, i);
        }
    }
}