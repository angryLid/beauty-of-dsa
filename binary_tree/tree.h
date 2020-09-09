/**
 * 实现一个二叉查找树，并且支持插入、删除、查找操作
 * 实现查找二叉查找树中某个节点的后继、前驱节点
 * 实现二叉树前、中、后序以及按层遍历
 */
#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
    struct node *parent;
} Node;

typedef struct bst
{
    struct node *root;
} BST;

BST *newBST()
{
    BST *bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

void insertValue(BST *tree, int value)
{
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    if (tree->root == NULL)
    {
        tree->root = n;
        return;
    }

    Node *curr = tree->root;
    while (curr != NULL)
    {
        if (value < curr->value)
        {
            if (curr->left == NULL)
            {
                curr->left = n;
                return;
            }
            curr = curr->left;
            // continue;
        }
        else

        // if (value >= curr->value)
        {
            if (curr->right == NULL)
            {
                curr->right = n;
                return;
            }
            curr = curr->right;
            // continue;
        }
    }
}

int searchValue(BST *tree, int value)
{
    Node *curr = tree->root;
    while (curr != NULL)
    {
        if (value < curr->value)
            curr = curr->left;
        else if (value > curr->value)
            curr = curr->right;
        else
            return 0;
    }
    return -1;
}
// 内存泄漏不管了
int removeValue(BST *tree, int value)
{
    Node *p = tree->root;
    Node *pp = NULL;
    // pp记录p的父节点
    while (p != NULL && p->value != value)
    {
        pp = p;
        if (value > p->value)
            p = p->right;
        else
            p = p->left;
    }

    if (p == NULL)
        return -1;

    if (p->left != NULL && p->right != NULL)
    {
        Node *minP = p->right;
        Node *minPP = p;
        while (minP->left != NULL)
        {
            minPP = minP;
            minP = minP->left;
        }
        p->value = minP->value;
        p = minP;
        pp = minPP;
    }
    Node *child = NULL;
    if (p->left != NULL)
        child = p->left;
    else if (p->right != NULL)
        child = p->right;

    if (pp == NULL)
        tree->root = child;
    else if (pp->left = p)
        pp->left = child;
    else
        pp->right = child;
}

// 前序，中序，后序遍历
void preOrder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->value); // 此处为伪代码，表示打印root节点
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}

void postOrder(Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}

/**
 * https://www.jianshu.com/p/4cb355a6cad0
 */
//前驱元素
//节点val值小于该节点val值并且值最大的节点
Node *predecessor(Node *node)
{
    Node *ret = NULL;
    // 如果x存在左孩子，则"x的前驱结点"为 "以其左孩子为根的子树的最大结点"。
    if (node->left != NULL)
    {
        Node *r = node->left;
        while (r->right)
        {
            r = r->right;
        }
        ret = r;
    }
    else
    {
        // 如果x没有左孩子。则x有以下两种可能：
        // (01) x是"一个右孩子"，则"x的前驱结点"为 "它的父结点"。
        // (01) x是"一个左孩子"，则查找"x的最低的父结点，并且该父结点要具有右孩子"，找到的这个"最低的父结点"就是"x的前驱结点"。
        ret = node->parent;
        while ((ret != NULL) && (node == ret->left))
        {
            node = ret;
            ret = ret->parent;
        }
    }
    return ret;
}

//后继元素
//节点val值大于该节点val值并且值最小的节点
Node *successor(Node *node)
{
    Node *ret = NULL;
    if (node->right != NULL)
    {
        Node *l = node->right;
        while (l->left)
        {
            l = l->left;
        }
        ret = l;
    }
    else
    {
        // 如果x没有右孩子。则x有以下两种可能：
        // (01) x是"一个左孩子"，则"x的后继结点"为 "它的父结点"。
        // (02) x是"一个右孩子"，则查找"x的最低的父结点，并且该父结点要具有左孩子"，找到的这个"最低的父结点"就是"x的后继结点"。
        ret = node->parent;
        while ((ret != NULL) && (node == ret->right))
        {
            node = ret;
            ret = ret->parent;
        }
    }
    return ret;
}

#endif /* TREE_H */