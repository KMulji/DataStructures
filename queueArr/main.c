#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int *arr;
    int size;
    int len;
    int top;
    int end;
};

struct Queue *Create(int size)
{
    struct Queue *qt = (struct Queue *)malloc(sizeof(struct Queue));
    qt->arr = (int *)malloc(size * sizeof(size));
    qt->len = 0;
    qt->size = size;
    qt->top = -1;
    qt->end = -1;
    return qt;
}

void Enqueue(struct Queue *qt, int elem)
{
    if (qt->len == qt->size)
    {
        printf("Queue is full\n");
        return;
    }
    if (qt->len == 0)
    {
        qt->len++;
        qt->top++;
        qt->end++;
        qt->arr[qt->end] = elem;
        return;
    }
    qt->end++;
    qt->arr[qt->end] = elem;
    qt->len++;
}
int Dequeue(struct Queue *qt)
{
    if (qt->len==0)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int x = -1;
    x = qt->top;
    qt->top++;
    qt->len--;
    return x;
}
void Display(struct Queue *qt)
{
    if (qt->len==0)
    {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < qt->len; i++)
    {
        printf("%d ", qt->arr[i]);
    }
    printf("\n");
    printf("Size is->%d Len is -> %d top is-> %d end is-> %d\n", qt->size, qt->len, qt->top, qt->end);
}
int main()
{
    struct Queue *qt = Create(10);

    for (int i = 0; i < 10; i++)
    {
        Enqueue(qt, i);
    }
    Display(qt);
    for (int i = 0; i < 10; i++)
    {
        printf("Removing %d\n", Dequeue(qt));
    }
    Display(qt);
    return 0;
}
