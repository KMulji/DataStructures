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
    /*Finds a single missing elemets in a sorted array*/
    void SingleMissingElem();
    /*Finds multiple missing elements in a sorted array*/
    void MultipleMissingElem();
    /*Find multiple missing elements in a unsorted array*/
    void MultMissing();
    /*Display the duplicates in the sorted array*/
    void DisplayDuplicates();
    /*Display the duplicates along with the count in a sorted array*/
    void DisplayDuplicatesCount();
    /*Display the duplicates along with count in a sorted/unsorted array*/
    void DisplayDuplicatesCount2();
    /*Display the duplicates along with the count in a sorted array using inefficient method*/
    void DisplayDuplicatesCount3();
    /*Find a pair with a sum of k in a unsorted/sorted array*/
    void TwoSum(int k);
    /*Fina a pair with sum of k in a sorted array*/
    void TwoSumSorted(int k);
};
#endif