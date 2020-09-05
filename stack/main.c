#include <stdio.h>
#include "stack.h"
int main()
{
    Stack *s = newStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    toString(s);
    pop(s);
    pop(s);
    toString(s);

    LinkedStack *ls = newLinkedStack();
    push_(ls, 22);
    toString_(ls);
    pop_(ls);
    toString_(ls);
    push_(ls, 11);
    toString_(ls);
    push_(ls, 44);
    toString_(ls);
    push_(ls, 99);
    toString_(ls);
    pop_(ls);
    toString_(ls);
    pop_(ls);
    toString_(ls);

    Browser *b = newBrowser();
    forward(b);
    back(b);
    open(b, 0);
    open(b, 1);
    open(b, 2);
    open(b, 3);
    open(b, 4);
    open(b, 5);
    back(b);
    back(b);
    back(b);
    back(b);
    forward(b);
    forward(b);
    open(b, 11);
    open(b, 12);
    back(b);
    back(b);
    back(b);
    back(b);
    back(b);
    back(b);
    forward(b);
    forward(b);
    forward(b);
    forward(b);
    forward(b);
    forward(b);
    forward(b);
    forward(b);
    forward(b);

    return 0;
}
