#include <stdlib.h>
#include <stdio.h>

struct PriorityQueue
{
    int A[100];
    int len;
};

struct PriorityQueue *Create()
{
    struct PriorityQueue *pq = (struct PriorityQueue *)malloc(sizeof(struct PriorityQueue));
    pq->len = 0;
    return pq;
}

void Insert(struct PriorityQueue *pq, int elem)
{
    if (pq->len == 0)
    {
        pq->A[0] = elem;
        pq->len++;
        return;
    }
    if (pq->len == 100)
    {
        printf("Priority Queue is full\n");
        return;
    }
    int j = 0;
    while (elem < pq->A[j])
    {
        j++;
    }
    int i = pq->len - 1;
    while (i >= j)
    {
        pq->A[i + 1] = pq->A[i];
        i--;
    }
    pq->A[i + 1] = elem;
    pq->len++;
}

int Delete(struct PriorityQueue *pq)
{
    if (pq->len == 0)
    {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int ans = -1;

    ans = pq->A[pq->len - 1];
    pq->A[pq->len - 1] = 0;
    pq->len--;

    return ans;
}
int MaxVal(struct PriorityQueue *pq)
{
    if (pq->len == 0)
    {
        printf("Priority Queue is empty\n");
        return -1;
    }
    return pq->A[pq->len - 1];
}
void Display(struct PriorityQueue *pq)
{
    for (int i = 0; i < pq->len; i++)
    {
        printf("%d ", pq->A[i]);
    }
    printf("\n");
}
int main()
{
    struct PriorityQueue *pq = Create();

    Insert(pq, 15);
    Insert(pq, 10);
    Insert(pq, 8);
    Insert(pq, 6);
    Delete(pq);
    Insert(pq, 9);
    Insert(pq, 11);
    Delete(pq);
    printf("Max Value is %d\n", MaxVal(pq));
    Display(pq);
    return 0;
}
