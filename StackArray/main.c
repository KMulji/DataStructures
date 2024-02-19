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
        int *temp = (int *)malloc(2 * st->size * sizeof(int));
        for (int i = 0; i < st->length; i++)
        {
            temp[i] = st->a[i];
        }
        st->size = 2 * st->size;
        free(st->a);
        st->a = temp;
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
    if (st->length <= st->size * 0.5)
    {
        st->size = 0.5 * st->size;
        int *temp = (int *)malloc(st->size * sizeof(int));
        for (int i = 0; i < st->length; i++)
        {
            temp[i] = st->a[i];
        }
        free(st->a);
        st->a = temp;
    }
    int ans = st->top;
    st->a[st->top] = 0;
    st->top--;
    st->length--;
    return ans;
}
int Peek(struct Stack *st, int index)
{
    if (st->top - index < 0)
    {
        printf("Invalid Index\n");
        return -1;
    }
    return st->a[st->top - index];
}
int StackTop(struct Stack *st)
{
    return st->top == -1 ? -1 : st->a[st->top];
}
int main()
{
    struct Stack *temp = Create(5);
    Push(temp, 10);
    
    printf("%d\n", StackTop(temp));
    Display(temp);
}