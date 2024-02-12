#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int val;
    struct Node *next;
};
struct CircleList
{
    struct Node *Head;
    struct Node *Tail;
    int length;
};
struct CircleList *Create(int A[], int n)
{
    struct CircleList *ans = (struct CircleList *)malloc(sizeof(struct CircleList));
    ans->length = n;
    ans->Head = (struct Node *)malloc(sizeof(struct Node));
    ans->Head->val = A[0];
    ans->Head->next = ans->Head;

    ans->Tail = ans->Head;

    for (int i = 1; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct CircleList));
        temp->val = A[i];
        ans->Tail->next = temp;
        ans->Tail = temp;
    }
    ans->Tail->next = ans->Head;
    return ans;
}
void Display(struct CircleList *cl)
{
    struct Node *curr = cl->Head;

    do
    {
        printf("%d ", curr->val);
        curr = curr->next;
    } while (curr != cl->Head);
    printf("\n");
}
void RecursiveDisplay(struct Node *curr, struct CircleList *ll)
{
    static int Flag = 0;

    if (Flag == 0 || curr != ll->Head)
    {
        Flag = 1;
        printf("%d ", curr->val);
        RecursiveDisplay(curr->next, ll);
    }
    Flag = 0;
}
void Insert(int pos, int elem, struct CircleList *ll)
{
    if (pos < 0 || pos > ll->length + 1)
    {
        printf("Out of index\n");
        return;
    }
    if (pos == 0)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = elem;

        temp->next = ll->Head;
        ll->Head = temp;
        ll->Tail->next = ll->Head;
        ll->length++;
        return;
    }
    if (pos == ll->length)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = elem;

        ll->Tail->next = temp;
        ll->Tail = temp;
        ll->Tail->next = ll->Head;
        ll->length++;
        return;
    }
    struct Node *p = ll->Head;
    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;

    temp->next = p->next;
    p->next = temp;
    ll->length++;
}
int Delete(int pos, struct CircleList *cl)
{
    if (pos < 0 || pos >= cl->length)
    {
        printf("Out of Bounds\n");
        return -1;
    }
    if (!cl->Head || !cl->Tail)
    {
        printf("List is empty");
        return -1;
    }
    if (pos == 0)
    {
        struct Node *temp = cl->Head;
        cl->Head = cl->Head->next;
        cl->Tail->next = cl->Head;
        int ans = temp->val;
        free(temp);
        return ans;
    }

    struct Node *q = NULL;
    struct Node *p = cl->Head;
    int i;
    for (i = 0; i < pos; i++)
    {
        q = p;
        p = p->next;
    }
    if (i == cl->length - 1)
    {
        int ans = -1;
        q->next = cl->Head;
        p->next = NULL;
        cl->Tail = q;
        ans = p->val;
        free(p);

        return ans;
    }
    int ans = p->val;
    q->next = p->next;
    p->next = NULL;
    cl->length--;
    free(p);
    return ans;
}
int main()
{
    int A[] = {1, 2, 3, 4, 5};
    struct CircleList *ans = Create(A, 5);
    Insert(5, 20, ans);
    Delete(5, ans);
    Display(ans);
    return 0;
}