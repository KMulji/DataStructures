#include <stdlib.h>
#include <stdio.h>

struct CircleQueue
{
    int *arr;
    int size;
    int top;
    int end;
};
struct CircleQueue *Create(int size)
{
    struct CircleQueue *qt = (struct CircleQueue *)malloc(sizeof(struct CircleQueue));
    qt->arr = (int *)malloc(size * sizeof(int));
    qt->size = size;
    qt->top = 0;
    qt->end = 0;
    return qt;
}
void Enqueue(struct CircleQueue *qt, int elem)
{
    // full queue
    if ((qt->end + 1) % qt->size == qt->top)
    {
        printf("Queue is full \n");
        return;
    }
    // add a element
    qt->end = (qt->end + 1) % qt->size;
    qt->arr[qt->end] = elem;
}
int Dequeue(struct CircleQueue *qt)
{
    int ans = -1;
    if (qt->top == qt->end)
    {
        printf("Queue is empty\n");
        return -1;
    }
    qt->top = (qt->top + 1) % qt->size;
    ans = qt->arr[qt->top];
    qt->arr[qt->top] = 0;
    return ans;
}
void Display(struct CircleQueue q)
{

    int i = q.top + 1;
    do
    {
        printf("%d ", q.arr[i]);
        i = (i + 1) % q.size;
    } while (i != (q.end + 1) % q.size);

    printf("\n");
}

int main()
{
    struct CircleQueue *qt = Create(6);
    for (int i = 0; i < 3; i++)
    {
        Enqueue(qt, i);
    }

    for (int i = 0; i < 1; i++)
    {
        printf("%d \n", Dequeue(qt));
    }
    Display(*qt);
    return 0;
}