/**
 * 用数组实现一个顺序栈
 * 用链表实现一个链式栈
 * 编程模拟实现一个浏览器的前进、后退功能
*/

#ifndef STACK_H
#define STACK_H
typedef struct _stack
{
    int *a;
    int size;
    int count;
} Stack;

Stack *newStack();
void toString(Stack *s);
void push(Stack *s, int val);
int pop(Stack *s);
void empty(Stack *s);
int top(Stack *s);
int isEmpty(Stack *s);

typedef struct _node
{
    int val;
    struct _node *next;
    struct _node *prev;
} Node;

typedef struct __stack
{
    Node *head;
    Node *tail;
} LinkedStack;

LinkedStack *newLinkedStack();
void toString_(LinkedStack *s);
void push_(LinkedStack *s, int val);
int pop_(LinkedStack *s);

typedef struct browser
{
    Stack *x;
    Stack *y;
} Browser;

Browser *newBrowser();
void open(Browser *b, int page);
void forward(Browser *b);
void back(Browser *b);
void curr();
#endif /* STACK_H */