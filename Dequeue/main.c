#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int val;
    struct Node *next;
    struct Node *prev;
};
struct Dequeue
{
    struct Node *Head;
    struct Node *Tail;
    int length;
};
struct Dequeue *Create()
{
    struct Dequeue *temp = (struct Dequeue *)malloc(sizeof(struct Dequeue));
    temp->Head = NULL;
    temp->Tail = NULL;
    temp->length = 0;
}
void InsertFront(struct Dequeue *dt, int elem)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;
    temp->next = NULL;
    temp->prev = NULL;
    if (!dt->Head || !dt->Tail)
    {
        dt->Head = temp;
        dt->Tail = temp;
        return;
    }
    temp->next = dt->Head;
    dt->Head->prev = temp;
    dt->Head = temp;
}
int DeleteTop(struct Dequeue *dt)
{
    int ans = -1;
    struct Node *temp;
    if (!dt->Head || !dt->Tail)
    {
        printf("Dequeue is empty\n");
        return ans;
    }
    if (!dt->Head->next)
    {
        ans = dt->Head->val;
        free(dt->Head);
        dt->Head = NULL;
        dt->Tail = NULL;
        return ans;
    }
    temp = dt->Head;
    dt->Head = dt->Head->next;
    ans = temp->val;
    temp->next = NULL;
    free(temp);

    return ans;
}
void InsertRear(struct Dequeue *dt, int elem)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;
    temp->next = NULL;
    temp->prev = NULL;
    if (!dt->Head || !dt->Tail)
    {
        dt->Head = temp;
        dt->Tail = temp;
        return;
    }
    dt->Tail->next = temp;
    temp->prev = dt->Tail;
    dt->Tail = dt->Tail->next;
}
int DeleteRear(struct Dequeue *dt)
{
    int ans = -1;
    struct Node *temp;
    if (!dt->Head || !dt->Tail)
    {
        printf("Dequeue is empty\n");
        return ans;
    }
    if (!dt->Head->next)
    {
        ans = dt->Head->val;
        free(dt->Head);
        dt->Head = NULL;
        dt->Tail = NULL;
        return ans;
    }
    temp = dt->Tail;
    dt->Tail = dt->Tail->prev;
    dt->Tail->next = NULL;
    ans = temp->val;
    free(temp);
    return ans;
}
void Display(struct Dequeue qt)
{
    if (!qt.Head || !qt.Tail)
    {
        printf("Dequeue is empty\n");
        return;
    }
    struct Node *curr = qt.Head;

    while (curr)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
int main()
{
    struct Dequeue *dt = Create();

    for (int i = 0; i < 5; i++)
    {
        InsertRear(dt, i + 1);
    }
    Display(*dt);
    printf("Removed %d\n", DeleteRear(dt));
    printf("Removed %d\n", DeleteTop(dt));
    Display(*dt);
    printf("Removed %d\n", DeleteRear(dt));
    printf("Removed %d\n", DeleteTop(dt));
    Display(*dt);
    printf("Removed %d\n", DeleteTop(dt));
    Display(*dt);
}