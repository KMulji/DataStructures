#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int val;
    struct Node *left;
    struct Node *right;
    int height;
};
struct AVL
{
    struct Node *root;
};

int CalcNodeHeight(struct Node *p)
{
    int hl;
    int hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}
int NodeBalanceFactor(struct Node *p)
{
    int hl;
    int hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl - hr;
}
struct Node *LLRotation(struct Node *p, struct AVL *avl)
{
    struct Node *pl = p->left;
    struct Node *plr = pl->right;

    pl->right = p;
    p->left = plr;

    p->height = CalcNodeHeight(p);
    pl->height = CalcNodeHeight(pl);

    if (avl->root == p)
    {
        avl->root = pl;
    }
    return pl;
}
struct Node *RRotation(struct Node *p, struct AVL *avl)
{
    struct Node *pr = p->right;
    struct Node *prl = pr->left;

    pr->left = p;
    p->right = prl;

    p->height = CalcNodeHeight(p);
    pr->height = CalcNodeHeight(pr);

    if (p == avl->root)
    {
        avl->root = pr;
    }

    return pr;
}
struct Node *Insert(struct Node *r, int key, struct AVL *avl)
{
    if (r == NULL)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = key;
        temp->left = NULL;
        temp->right = NULL;
        temp->height = 1;
        if (!avl->root)
        {
            avl->root = temp;
        }
        return temp;
    }
    if (key < r->val)
    {
        r->left = Insert(r->left, key, avl);
    }
    else if (key > r->val)
    {
        r->right = Insert(r->right, key, avl);
    }
    r->height = CalcNodeHeight(r);
    if (NodeBalanceFactor(r) == 2 && NodeBalanceFactor(r->left) == 1)
    {
        return LLRotation(r, avl);
    }
    else if (NodeBalanceFactor(r) == -2 && NodeBalanceFactor(r->right) == -1)
    {
        return RRotation(r, avl);
    }
    return r;
}

int main()
{
    struct AVL *avl = (struct AVL *)malloc(sizeof(struct AVL));
    Insert(avl->root, 10, avl);
    Insert(avl->root, 15, avl);
    Insert(avl->root, 20, avl);
    Insert(avl->root, 30, avl);
    Insert(avl->root, 40, avl);

    printf("......\n");
    return 0;
}