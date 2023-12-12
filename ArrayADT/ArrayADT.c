#include <stdlib.h>
#include <stdio.h>
#include "ArrayADT.h"
#include <limits.h>
struct ArrayADT Init(int size)
{
    struct ArrayADT x;
    x.size = size;
    x.length = 0;
    x.p = (int *)malloc(size * sizeof(int));
    return x;
}
struct ArrayADT *InitH(int size)
{
    struct ArrayADT *x = (struct ArrayADT *)malloc(sizeof(struct ArrayADT));
    x->size = size;
    x->length = 0;
    x->p = (int *)malloc(size * sizeof(int));
    return x;
}
void Display(struct ArrayADT *a)
{
    for (int i = 0; i < a->length; i++)
    {
        printf("%d ", a->p[i]);
    }
    printf("\n");
}
void Append(struct ArrayADT *a, int elem)
{

    if (a->length == a->size)
    {

        a->size = 2 * a->size;
        a->p = Grow(a->p, 2 * a->size,a->length);
    }

    a->p[a->length] = elem;
    a->length++;
}
void Insert(struct ArrayADT *a, int idx, int elem)
{
    if (idx < 0 || idx > a->length)
    {
        printf("Error out of bounds\n");
        return;
    }
    if (a->length == a->size)
    {
        // resize array
        a->size = 2 * a->size;
        a->p = Grow(a->p, a->size,a->length);
    }
    int r = a->length;
    while (r != idx)
    {
        a->p[r] = a->p[r - 1];
        r--;
    }
    a->p[idx] = elem;
    a->length++;
}
int Delete(struct ArrayADT *a, int idx)
{
    if (idx < 0 || idx > a->length - 1)
    {
        return -1;
    }
    if (a->length == a->size / 2)
    {
        a->size = a->size *0.5;
        a->p = Shrink(a->p, a->length, a->size);
    }
    int ans = a->p[idx];

    for (int i = idx; i < a->length - 1; i++)
    {
        a->p[i] = a->p[i + 1];
    }
    a->length--;

    return ans;
}
int *Grow(int *p, int newSize,int length)
{
    int *temp = (int *)malloc(newSize * sizeof(int));
    int i;
    for (i = 0; i < length; i++)
    {
        temp[i] = p[i];
    }
    free(p);
    p = temp;
    temp = NULL;
    return p;
}
int *Shrink(int *olds, int length, int newSize)
{
    int *temp = (int *)malloc(newSize * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        temp[i] = olds[i];
    }
    free(olds);
    olds = temp;
    temp = NULL;
    return olds;
}
int LinearSearch(struct ArrayADT *a, int key)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->p[i] == key)
        {
            return i;
        }
    }
    return -1;
}
int LinearSearch1(struct ArrayADT *a, int key)
{

    for (int i = 0; i < a->length; i++)
    {
        if (a->p[i] == key)
        {
            int temp = a->p[0];
            a->p[0] = a->p[i];
            a->p[i] = temp;

            return 0;
        }
    }
    return -1;
}
int LinearSearch2(struct ArrayADT *a, int key)
{
    for (int i = 0; i < a->length; i++)
    {
        if (a->p[i] == key)
        {
            int temp = a->p[i];
            a->p[i] = a->p[i - 1];
            a->p[i - 1] = temp;

            return i;
        }
    }
    return -1;
}
int BinSearch(struct ArrayADT *a, int key)
{
    int lo = 0;
    int hi = a->length - 1;
    int mid = -1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (a->p[mid] == key)
        {
            return mid;
        }
        if (key < a->p[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return -1;
}
int BinSearchRecur(struct ArrayADT *a, int key, int lo, int hi, int mid)
{
    if (lo > hi)
    {
        return -1;
    }
    mid = lo + (hi - lo) / 2;
    if (a->p[mid] == key)
    {
        return mid;
    }
    if (key < a->p[mid])
    {
        return BinSearchRecur(a, key, lo, hi = mid - 1, mid);
    }
    else
    {
        return BinSearchRecur(a, key, lo = mid + 1, hi, mid);
    }
    return -1;
}
int Get(struct ArrayADT *p, int x)
{
    if (x < 0 || x > p->length - 1)
    {
        printf("index out of bound");
        return -1;
    }
    return p->p[x];
}
void Set(struct ArrayADT *p, int x, int elem)
{
    if (x < 0 || x > p->length - 1)
    {
        printf("index out of bound");
        
    }
    p->p[x] = elem;
}
int Max(struct ArrayADT *p)
{
    int ans = INT_MIN;
    for (int i = 0; i < p->length; i++)
    {
        if (p->p[i] >= ans)
        {
            ans = p->p[i];
        }
    }
    return ans;
}
int Min(struct ArrayADT *p)
{
    int ans = INT_MAX;
    for (int i = 0; i < p->length; i++)
    {
        if (p->p[i] <= ans)
        {
            ans = p->p[i];
        }
    }
    return ans;
}
int Sum(struct ArrayADT *p)
{
    int sum = 0;
    for (int i = 0; i < p->length; i++)
    {
        sum += p->p[i];
    }
    return sum;
}
float Avg(struct ArrayADT *p)
{
    float total = 0.f;
    for (int i = 0; i < p->length; i++)
    {
        total += p->p[i];
    }
    return total / p->length;
}
void Reverse(struct ArrayADT *a)
{
    if (!a)
    {
        return;
    }
    if (!a->p)
    {
        return;
    }
    int *p = &a->p[0];
    int *q = &a->p[a->length - 1];

    while (p != q)
    {
        int temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}
void InsertSorted(struct ArrayADT *a, int elem)
{
    if (!a)
    {
        return;
    }
    if (!a->p)
    {
        return;
    }
    if (a->size == a->length)
    {
        // resize
        Grow(a->p, 2 * a->size,a->length);
    }
    int q = a->length - 1;

    while (q >= 0 && a->p[q] > elem)
    {

        a->p[q + 1] = a->p[q];
        q--;
    }
    a->p[q + 1] = elem;
    a->length++;
}
int IsSorted(struct ArrayADT *a)
{
    if (!a)
    {
        return -2;
    }
    if (!a->p)
    {
        return -3;
    }
    for (int i = 0; i < a->length - 1; i++)
    {
        if (a->p[i] > a->p[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void NegativeSort(struct ArrayADT *p)
{
    int i = 0;
    int j = p->length - 1;

    while (i < j)
    {
        while (p->p[i] < 0)
        {
            i++;
        }
        while (p->p[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&p->p[i], &p->p[j]);
        }
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Merge(struct ArrayADT *p, struct ArrayADT *q, struct ArrayADT *a)
{

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < p->length && j < q->length)
    {
        if (p->p[i] < q->p[j])
        {
            a->p[k] = p->p[i];
            a->length++;
            i++;
            k++;
        }
        else
        {
            a->p[k] = q->p[j];
            a->length++;
            j++;
            k++;
        }
    }
    for (; i < p->length; i++)
    {
        a->p[k] = p->p[i];
        a->length++;
        k++;
    }
    for (; j < q->length; j++)
    {
        a->p[k] = q->p[j];
        a->length++;
        k++;
    }
}
void Union(struct ArrayADT *p, struct ArrayADT *q, struct ArrayADT *a)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < p->length && j < q->length)
    {
        if (p->p[i] < q->p[j])
        {
            a->p[k] = p->p[i];
            i++;
            k++;
        }
        else if (q->p[j] < p->p[i])
        {
            a->p[k] = q->p[j];
            j++;
            k++;
        }
        else
        {
            a->p[k] = p->p[i];
            i++;
            k++;
            j++;
        }
    }
    for (; i < p->length; i++)
    {
        a->p[k] = p->p[i];
        k++;
    }
    for (; j < q->length; j++)
    {

        a->p[k] = q->p[j];
        k++;
    }
    a->length = k;
}
void Intersection(struct ArrayADT *p, struct ArrayADT *q, struct ArrayADT *a)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < p->length && j < q->length)
    {
        if (p->p[i] < q->p[j])
        {

            i++;
        }
        else if (q->p[j] < p->p[i])
        {

            j++;
        }
        else if (p->p[i] == q->p[j])
        {
            a->p[k] = p->p[i];
            i++;
            j++;
            k++;
            
        }
    }
    a->length=k;
}
void Difference(struct ArrayADT*p,struct ArrayADT*q,struct ArrayADT *a){
    int i=0;
    int j=0;
    int k=0;

    while(i<p->length&&j<q->length){

        if(p->p[i]<q->p[j]){
            a->p[k]=p->p[i];
            i++;
            k++;
        }else if(q->p[j]<p->p[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }
    for(;i<p->length;i++){
        a->p[k]=p->p[i];
        k++;
    }
    a->length=k;
}