#include <stdlib.h>
#include <stdio.h>

struct Stack
{
    int *a;
    int length;
    int size;
    int top;
};

struct Stack *Create(int size)
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->top = -1;
    st->size = size;
    st->length = 0;
    st->a = (int *)malloc(size * sizeof(int));
    return st;
}

void Push(struct Stack *st, int val)
{
    if (st->length == st->size)
    {
        printf("Stack overflow\n");
        return;
    }
    st->top++;
    st->a[st->top] = val;
    st->length++;
}

void Display(struct Stack *st)
{
    for (int i = st->length - 1; i >= 0; i--)
    {
        printf("%d ", st->a[i]);
    }
    printf("\n");
}
int Pop(struct Stack *st)
{
    if (st->length == 0)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    int ans = st->top;
    st->a[st->top] = 0;
    st->top--;
    st->length--;
    return ans;
}
int Peek(struct Stack *st, int index)
{
    if(st->top-index+1<0)
    {
        printf("Invalid Index\n");
        return -1;
    }
    return st->a[st->top-index+1];
}
int main()
{
    struct Stack *temp = Create(5);
    Push(temp, 10);
    Push(temp, 20);
    Push(temp, 30);
    Push(temp, 40);
    Push(temp, 50);
    Pop(temp);
    Pop(temp);
    Display(temp);
}