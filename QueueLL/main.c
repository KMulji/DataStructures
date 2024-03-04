#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int val;
    struct Node *next;
};

struct Queue
{
    struct Node *Top;
    struct Node *Tail;
    int length;
};

struct Queue *Create()
{
    struct Queue *qt = (struct Queue *)malloc(sizeof(struct Queue));
    qt->Tail = NULL;
    qt->Top = NULL;
    qt->length = 0;
    return qt;
}
void Enqueue(struct Queue *qt, int elem)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;
    temp->next = NULL;
    if (!qt->Top || !qt->Tail)
    {
        qt->Top = temp;
        qt->Tail = temp;
        qt->length++;
        return;
    }

    qt->Tail->next = temp;
    qt->Tail = qt->Tail->next;
    qt->length++;
}
int Dequeue(struct Queue *qt)
{
    int ans = -1;
    if (!qt->Top || !qt->Tail)
    {
        printf("Queue is empty\n");
        return -1;
    }
    if (qt->Top == qt->Tail)
    {
        ans = qt->Top->val;
        free(qt->Top);
        qt->Tail = NULL;
        qt->Top = NULL;
        qt->length++;
        return ans;
    }
    struct Node *temp = qt->Top;

    qt->Top = qt->Top->next;
    ans = temp->val;
    free(temp);
    qt->length++;
    return ans;
}
void Display(struct Queue *qt)
{
    struct Node *curr = qt->Top;

    if (!curr)
    {
        printf("Queue is empty\n");
        return;
    }
    while (curr)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
int main()
{
    struct Queue *qt = Create();
    for (int i = 0; i < 5; i++)
    {
        Enqueue(qt, i + 1);
    }
    Display(qt);

    for (int i = 0; i < 5; i++)
    {
        printf("Removing %d ", Dequeue(qt));
    }
    Display(qt);

    return 0;
}