#include <stdlib.h>
#ifndef ARRAYADT_H
#define ARRAYADT_H
struct ArrayADT
{
    int *p;
    int length;
    int size;
};
struct ArrayADT Init(int size);
struct ArrayADT *InitH(int size);
void Display(struct ArrayADT *a);
void Append(struct ArrayADT *a, int elem);
void Insert(struct ArrayADT *a, int idx, int elem);
int Delete(struct ArrayADT *a,int idx);
int *Grow(int *old, int newSize,int length);
int *Shrink(int* olds,int length,int newSize);
int LinearSearch(struct ArrayADT *a, int key);
int LinearSearch1(struct ArrayADT *a, int key);
int LinearSearch2(struct ArrayADT *a, int key);
int BinSearch(struct ArrayADT *a,int key);
int BinSearchRecur(struct ArrayADT *a ,int key,int lo,int hi,int mid);
int Get(struct ArrayADT*p,int x);
void Set(struct ArrayADT*p,int x,int elem);
int Max(struct ArrayADT* p);
int Min(struct ArrayADT* p);
int Sum(struct ArrayADT* p);
float Avg(struct ArrayADT* p);
void Reverse(struct ArrayADT* p);
void InsertSorted(struct ArrayADT* a,int elem);
int IsSorted(struct ArrayADT* a);
void NegativeSort(struct ArrayADT *p);
void swap(int *a,int*b);
void Merge(struct ArrayADT*p,struct ArrayADT*q,struct ArrayADT *a);
void Union(struct ArrayADT*p,struct ArrayADT*q,struct ArrayADT *a);
void Intersection(struct ArrayADT*p,struct ArrayADT*q,struct ArrayADT *a);
void Difference(struct ArrayADT*p,struct ArrayADT*q,struct ArrayADT *a);
#endif