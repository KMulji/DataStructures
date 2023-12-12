#ifndef ARRAYADT_H
#define ARRAYADT_H
#include <stdlib.h>
template <typename T>
class ArrayADT
{
private:
    T *p;
    int size;
    int length;
    T *Grow(T *old, int newSize, int length);
    T *Shrink(T *olds, int length, int newSize);

    void swap(T *a, T *b);

public:
    ArrayADT();
    ArrayADT(int size);
    ~ArrayADT() { delete[] this->p; };
    int GetLength() { return this->length; };
    void Display();
    void Append(T elem);
    void Insert(int idx, T elem);
    T Delete(int idx);
    int LinearSearch(T key);
    int BinSearch(T key);
    int BinSearchRecur(T key, int lo, int hi, int mid);
    T Get(int x);
    void Set(int x, T elem);
    T Max();
    T Min();
    T Sum();
    float Avg();
    void Reverse();
    void InsertSorted(T elem);
    bool IsSorted();
    void NegativeSort();
    void Merge(ArrayADT<T> *q, ArrayADT<T> *a);
    void Union( ArrayADT<T> *q, ArrayADT<T> *a);
    void Intersection(ArrayADT<T> *q, ArrayADT<T> *a);
    void Difference(ArrayADT<T> *q, ArrayADT<T> *a);
};
#endif