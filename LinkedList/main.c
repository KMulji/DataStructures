#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int val;
    struct Node *next;
};
struct LinkedList
{
    struct Node *Head;
    struct Node *Tail;
    int length;
};

struct LinkedList *Create(int A[], int n)
{
    struct LinkedList *ll = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    ll->length = 0;
    ll->Head = NULL;
    ll->Tail = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = A[i];
        temp->next = NULL;
        if (!ll->Head || !ll->Tail)
        {
            ll->Head = temp;
            ll->Tail = temp;
        }
        else
        {
            ll->Tail->next = temp;
            ll->Tail = temp;
        }
    }
    ll->length = i;
    return ll;
}
void Display(struct LinkedList *ll)
{
    struct Node *curr = ll->Head;

    while (curr)
    {
        printf("%d\n", curr->val);

        curr = curr->next;
    }
    printf("Length is %d", ll->length);
}
void RecursiveDisp(struct Node *curr)
{
    if (!curr)
    {
        return;
    }
    printf("%d\n", curr->val);
    RecursiveDisp(curr->next);
}
int count(struct LinkedList *ll)
{
    return ll->length;
}
int RecursiveCount(struct Node *curr)
{
    if (!curr)
    {
        return 0;
    }
    return 1 + RecursiveCount(curr->next);
}
int Sum(struct LinkedList *ll)
{
    struct Node *curr = ll->Head;
    int sum = 0;
    while (curr)
    {
        sum += curr->val;
        curr = curr->next;
    }
    return sum;
}
int RecursiveSum(struct Node *curr)
{
    if (!curr)
    {
        return 0;
    }

    return curr->val + RecursiveSum(curr->next);
}
int MaxElement(struct LinkedList *ll)
{
    int max = -20000;

    struct Node *curr = ll->Head;

    while (curr)
    {
        if (curr->val > max)
        {
            max = curr->val;
        }
        curr = curr->next;
    }

    return max;
}
int RecursiveMax(struct Node *curr)
{
    int max = -23744;

    if (!curr)
    {
        return max;
    }
    max = RecursiveMax(curr->next);
    if (curr->val > max)
    {
        return curr->val;
    }
    return max;
}

struct Node *LinearSearch(struct LinkedList *ll, int key)
{
    struct Node *curr = ll->Head;

    while (curr)
    {
        if (curr->val == key)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
int main()
{
    int A[] = {2, 4, 60, 8};
    struct LinkedList *ll = Create(A, 4);

    RecursiveDisp(ll->Head);
    if (LinearSearch(ll, 80)==NULL)
    {
        printf("not found");
    }else{
        printf("search is %d", LinearSearch(ll, 80)->val);
    }
    return 0;
}
