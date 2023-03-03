#include <stdlib.h>
#include <stdio.h>
#include "ArrayADT.h"

struct ArrayADT *Init(int size)
{
    if (size <= 0)
    {
        return NULL;
    }
    struct ArrayADT *x = (struct ArrayADT *)malloc(sizeof(struct ArrayADT));
    x->A = (int *)malloc(size * sizeof(int));
    x->size = size;
    x->length = 0;
    return x;
}
void Append(struct ArrayADT *x, int element)
{
    if (x->length == x->size)
    {
        x->size = 2 * x->size;
        int *temp = (int *)malloc(2 * x->size * sizeof(int));
        for (int i = 0; i < x->length; i++)
        {
            temp[i] = x->A[i];
        }
        free(x->A);
        x->A = NULL;
        x->A = temp;
        temp = NULL;
        x->A[x->length] = element;
        x->length++;
    }
    else
    {
        x->A[x->length] = element;
        x->length++;
    }
}
void Display(struct ArrayADT *x)
{
    for (int i = 0; i < x->length; i++)
    {
        printf("%d\n", x->A[i]);
    }
    printf("\n");
}
void Insert(struct ArrayADT *x, int element, int index)
{
    if (index < 0 || index >= x->length)
    {
        printf("Index out of bounds\n");
        return;
    }
    if (x->length == x->size)
    {
        x->size = 2 * x->size;
        int *temp = (int *)malloc(2 * x->size * sizeof(int));
        for (int i = 0; i < x->length; i++)
        {
            temp[i] = x->A[i];
        }
        free(x->A);
        x->A = NULL;
        x->A = temp;
        temp = NULL;
        for (int i = x->length; i > index; i--)
        {
            x->A[i] = x->A[i - 1];
        }
        x->A[index] = element;
        x->length++;
    }
    else
    {
        for (int i = x->length; i > index; i--)
        {
            x->A[i] = x->A[i - 1];
        }
        x->A[index] = element;
        x->length++;
    }
}
int Delete(struct ArrayADT *x, int index)
{
    if (index < 0 || index >= x->length)
    {
        printf("Index out of bounds\n");
        return -1;
    }
    int deleted = -1;

    if (x->length == x->size * 1 / 2)
    {

        x->size = x->size * 1 / 2;
        int *temp = (int *)malloc(1 / 2 * x->size * sizeof(int));
        for (int i = 0; i < x->length; i++)
        {
            temp[i] = x->A[i];
        }
        free(x->A);
        x->A = NULL;
        x->A = temp;
        temp = NULL;
        deleted = x->A[index];
        for (int i = index; i < x->length; i++)
        {
            x->A[i] = x->A[i + 1];
        }
        x->length--;
    }
    else
    {
        deleted = x->A[index];
        for (int i = index; i < x->length; i++)
        {
            x->A[i] = x->A[i + 1];
        }
        x->length--;
    }

    return deleted;
}
int LinearSearch(struct ArrayADT *x, int key)
{
    for (int i = 0; i < x->length; i++)
    {
        if (x->A[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct ArrayADT *x, int key)
{
    int lo = 0;
    int hi = x->length - 1;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (x->A[mid] == key)
        {
            return mid;
        }
        else if (key<x->A[mid])
        {
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return -1;
}