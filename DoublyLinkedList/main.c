#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
};
struct Doubly
{
    int length;
    struct Node *Head;
    struct Node *Tail;
};
struct Doubly *Create(int A[], int n)
{
    struct Doubly *ans = (struct Doubly *)malloc(sizeof(struct Doubly));
    ans->length = n;

    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = A[0];
    temp->next = NULL;
    temp->prev = NULL;

    ans->Head = temp;
    ans->Tail = temp;

    for (int i = 1; i < n; i++)
    {
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = A[i];

        ans->Tail->next = temp;
        temp->prev = ans->Tail;
        ans->Tail = temp;
    }
    return ans;
}
void Display(struct Doubly *dl)
{
    struct Node *curr = dl->Head;
    while (curr)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
void Insert(int pos, int elem, struct Doubly *dl)
{
    if (pos < 0 || pos >= dl->length + 1)
    {
        printf("Invalid index\n");
        return;
    }
    if (pos == 0)
    {
        if (!dl->Head || !dl->Tail)
        {
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->val = elem;
            dl->Head = temp;
            dl->Tail = temp;
            dl->length++;
            return;
        }
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = elem;
        temp->next = dl->Head;
        temp->prev = NULL;

        dl->Head->prev = temp;
        dl->Head = temp;
        dl->length++;
        return;
    }
    if (pos == dl->length)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = elem;

        dl->Tail->next = temp;
        temp->prev = dl->Tail;
        dl->Tail = temp;
        dl->length++;
        return;
    }

    struct Node *p = dl->Head;

    for (int i = 0; i < pos - 1; i++)
    {
        p = p->next;
    }
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;

    temp->next = p->next;
    temp->prev = p;

    p->next->prev = temp;
    p->next = temp;
    dl->length++;
}
int Delete(int pos, struct Doubly *dl)
{
    if (!dl->Head || !dl->Tail)
    {
        printf("Cannot delete empty list\n");
        return -1;
    }
    if (pos == 0)
    {
        if (!dl->Head->next)
        {
            int ans = dl->Head->val;
            free(dl->Head);
            dl->length--;
            return ans;
        }
        int ans = 0;
        struct Node *temp;
        ans = temp->val;
        temp = dl->Head;
        dl->Head = dl->Head->next;

        dl->Head->prev = NULL;

        temp->next = NULL;
        free(temp);
        dl->length--;
        return ans;
    }
    if (pos == dl->length - 1)
    {
        struct Node *temp = dl->Tail;
        int ans = dl->Tail->val;
        dl->Tail = dl->Tail->prev;
        temp->prev = NULL;
        dl->Tail->next = NULL;
        dl->length--;
        free(temp);
        return ans;
    }
    struct Node *temp = dl->Head;
    for (int i = 0; i < pos; i++)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = NULL;
    temp->prev = NULL;
    int ans = temp->val;
    free(temp);
    dl->length--;
    return ans;
}
int main()
{
    int A[] = {2, 3, 4, 5, 6};

    struct Doubly *dl = Create(A, 5);

    Delete(1, dl);
    Delete(1, dl);
    Display(dl);
    printf("Length is %d \n", dl->length);
    return 0;
}