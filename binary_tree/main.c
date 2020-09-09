#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(int argc, char const *argv[])
{
    BST *bst = newBST();
    insertValue(bst, 5);
    insertValue(bst, 4);
    insertValue(bst, 6);
    insertValue(bst, 2);
    insertValue(bst, 7);
    insertValue(bst, 1);
    insertValue(bst, 8);
    preOrder(bst->root);
    printf("\n");
    inOrder(bst->root);
    printf("\n");
    postOrder(bst->root);
    printf("\n");

    Node *n0 = predecessor(bst->root->left);
    printf("%d\n",n0->value); //should be 2
    Node *n1 = successor(bst->root->right->right);
    printf("%d\n",n1->value);// should be 8
        return 0;
}
