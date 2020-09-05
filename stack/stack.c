#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *newStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->a = (int *)malloc(sizeof(int) * 64);
    s->size = 64;
    s->count = 0;
    return s;
}

void empty(Stack *s)
{
    int count = s->count;
    if (s->count == 0)
        return;
    for (int i = 0; i < count; i++)
    {
        pop(s);
    }
}
int isEmpty(Stack *s)
{
    if (s->count == 0)
        return 1;
    else
        return 0;
}
void toString(Stack *s)
{
    printf("[ ");
    for (int i = 0; i < s->count; i++)
        if (i + 1 == s->count)
            printf("%d ", s->a[i]);
        else
            printf("%d, ", s->a[i]);

    printf("]\n");
}
void push(Stack *s, int val)
{
    if (s->count == s->size)
    {
        printf("Stack is full.\n");
        return;
    }
    s->a[s->count++] = val;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("Empty stack.\n");
    }
    return s->a[--s->count];
}
int top(Stack *s)
{
    if (!isEmpty(s))
    {
        int offset = s->count - 1;
        return s->a[offset];
    }
    return -1;
}
LinkedStack *newLinkedStack()
{
    LinkedStack *s = (LinkedStack *)malloc(sizeof(LinkedStack));
    s->head = NULL;
    s->tail = NULL;
}

void toString_(LinkedStack *s)
{
    printf("[ ");
    for (Node *node = s->head; node != NULL; node = node->next)
        if (node->next == NULL)
            printf("%d ", node->val);
        else
            printf("%d, ", node->val);

    printf("]\n");
}
void push_(LinkedStack *s, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    if (s->head == NULL)
    {
        s->head = node;
        // if(s->tail == NULL)
        s->tail = node;
        return;
    }
    node->prev = s->tail;
    s->tail->next = node;
    s->tail = node;
    return;
}

int pop_(LinkedStack *s)
{
    if (s->head == NULL)
    {
        printf("Empty Stack.\n");
        return -1;
    }

    Node *node = s->tail;
    if (s->head == s->tail)
    {
        s->head = NULL;
        s->tail = NULL;
    }
    else
    {
        s->tail = s->tail->prev;
        s->tail->next = NULL;
    }

    int result = node->val;
    free(node);
    node = NULL;
    return result;
}

Browser *newBrowser()
{
    Browser *b = (Browser *)malloc(sizeof(Browser));
    b->x = newStack();
    b->y = newStack();
    return b;
}

void open(Browser *b, int page)
{
    push(b->x, page);
    empty(b->y);
    printf("Opened: Page %d\n", page);
}

void back(Browser *b)
{
    if (isEmpty(b->x))
    {
        printf("No opened page.\n");
        return;
    }

    int page = pop(b->x);

    if (isEmpty(b->x))
    {
        push(b->x, page);
        printf("Page %d is the original page. Wanna close the browser?\n", page);
        return;
    }
    // printf("is it reached?0");
    push(b->y, page);
    // printf("is it reached?");
    printf("From Page %d back to Page %d\n", page, top(b->x));
}

void forward(Browser *b)
{
    if (isEmpty(b->y))
    {
        printf("Cannot forward anymore.\n");
        return;
    }

    int tmp = top(b->x);
    int page = pop(b->y);
    push(b->x, page);

    printf("From Page %d forward to Page %d\n", tmp, page);
}