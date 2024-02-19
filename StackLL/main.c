#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int val;
    struct Node *next;
};
struct Stack
{
    struct Node *Top;
    int length;
};
struct Stack *Create()
{
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    st->Top = NULL;
    st->length = 0;
    return st;
}
void Push(struct Stack *st, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    if (!st->Top)
    {
        st->Top = temp;
        st->length++;
        return;
    }
    temp->next = st->Top;
    st->Top = temp;
}
int Pop(struct Stack *st)
{
    struct Node *temp = NULL;
    if (!st->Top)
    {
        printf("Cannot pop from empty stack\n");
        return -1;
    }

    int ans = -1;
    if (!st->Top->next)
    {

        temp = st->Top;
        free(st->Top);
        st->Top=NULL;
        return ans;
    }
    temp = st->Top;
    st->Top = st->Top->next;
    ans = temp->val;
    free(temp);
    return ans;
}
void Display(struct Stack *st)
{
    if (!st->Top)
    {
        printf("Stack is empty");
        return;
    }
    struct Node *curr = st->Top;
    while (curr)
    {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}
int main()
{
    struct Stack *st = Create();
    Push(st, 1);
    Push(st, 2);
    Push(st, 3);
    Push(st, 4);
    Push(st, 5);

    Pop(st);
    Pop(st);
    Pop(st);
    Pop(st);
    
    
    Display(st);
}