#include <iostream>
#include <stdlib.h>
#include "ArrayADT.hpp"
#include <limits.h>
template <typename T>
ArrayADT<T>::ArrayADT()
{
    this->size = 10;
    this->length = 0;
    this->p = new T[this->size];
}
template <typename T>
ArrayADT<T>::ArrayADT(int size)
{
    this->size = size;
    this->length = 0;
    this->p = new T[this->size];
}
template <typename T>
T *ArrayADT<T>::Grow(T *old, int newSize, int length)
{
    T *temp = new T[newSize];
    int i;
    for (i = 0; i < length; i++)
    {
        temp[i] = p[i];
    }
    delete[] old;
    old = temp;
    temp = nullptr;
    return old;
}
template <typename T>
T *ArrayADT<T>::Shrink(T *olds, int length, int newSize)
{
    T *temp = new T[newSize];
    for (int i = 0; i < length; i++)
    {
        temp[i] = olds[i];
    }
    delete[] olds;
    olds = temp;
    temp = nullptr;
    return olds;
}
template <typename T>
void ArrayADT<T>::swap(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}
template <typename T>
void ArrayADT<T>::Display()
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << this->p[i] << " ";
    }
    std::cout << std::endl;
}
template <typename T>
void ArrayADT<T>::Append(T elem)
{
    if (this->length == this->size)
    {

        this->size = 2 * this->size;
        this->p = Grow(this->p, 2 * this->size, this->length);
    }

    this->p[this->length] = elem;
    this->length++;
}
template <typename T>
void ArrayADT<T>::Insert(int idx, T elem)
{
    if (idx < 0 || idx > this->length)
    {
        printf("Error out of bounds\n");
        return;
    }
    if (this->length == this->size)
    {
        // resize array
        this->size = 2 * this->size;
        this->p = Grow(this->p, this->size, this->length);
    }
    int r = this->length;
    while (r != idx)
    {
        this->p[r] = this->p[r - 1];
        r--;
    }
    this->p[idx] = elem;
    this->length++;
}
template <typename T>

T ArrayADT<T>::Delete(int idx)
{
    if (idx < 0 || idx > this->length - 1)
    {
        return -1;
    }
    if (this->length == this->size / 2)
    {
        this->size = this->size * 0.5;
        this->p = Shrink(this->p, this->length, this->size);
    }
    int ans = this->p[idx];

    for (int i = idx; i < this->length - 1; i++)
    {
        this->p[i] = this->p[i + 1];
    }
    this->length--;

    return ans;
}
template <typename T>
int ArrayADT<T>::LinearSearch(T key)
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] == key)
        {
            return i;
        }
    }
    return -1;
}
template <typename T>
int ArrayADT<T>::BinSearch(T key)
{
    int lo = 0;
    int hi = this->length - 1;
    int mid = -1;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (this->p[mid] == key)
        {
            return mid;
        }
        if (key < this->p[mid])
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
template <typename T>
int ArrayADT<T>::BinSearchRecur(T key, int lo, int hi, int mid)
{
    if (lo > hi)
    {
        return -1;
    }
    mid = lo + (hi - lo) / 2;
    if (this->p[mid] == key)
    {
        return mid;
    }
    if (key < this->p[mid])
    {
        return BinSearchRecur(key, lo, hi = mid - 1, mid);
    }
    else
    {
        return BinSearchRecur(key, lo = mid + 1, hi, mid);
    }
    return -1;
}
template <typename T>
T ArrayADT<T>::Get(int x)
{
    if (x < 0 || x > this->length - 1)
    {
        printf("index out of bound");
        return -1;
    }
    return this->p[x];
}
template <typename T>
void ArrayADT<T>::Set(int x, T elem)
{
    if (x < 0 || x > this->length - 1)
    {
        printf("index out of bound");
    }
    this->p[x] = elem;
}
template <typename T>
T ArrayADT<T>::Max()
{
    T ans = INT_MIN;
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] >= ans)
        {
            ans = this->p[i];
        }
    }
    return ans;
}
template <typename T>
T ArrayADT<T>::Min()
{
    int ans = INT_MAX;
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] <= ans)
        {
            ans = this->p[i];
        }
    }
    return ans;
}
template <typename T>
T ArrayADT<T>::Sum()
{
    T sum = 0;
    for (int i = 0; i < this->length; i++)
    {
        sum += this->p[i];
    }
    return sum;
}
template <typename T>
float ArrayADT<T>::Avg()
{
    float total = 0.f;
    for (int i = 0; i < this->length; i++)
    {
        total += this->p[i];
    }
    return total / this->length;
}
template <typename T>
void ArrayADT<T>::Reverse()
{

    if (!this->p)
    {
        return;
    }
    T *p = &this->p[0];
    T *q = &this->p[this->length - 1];

    while (p != q)
    {
        T temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}
template <typename T>
void ArrayADT<T>::InsertSorted(T elem)
{

    if (!this->p)
    {
        return;
    }
    if (this->size == this->length)
    {
        // resize
        Grow(this->p, 2 * this->size, this->length);
    }
    int q = this->length - 1;

    while (q >= 0 && this->p[q] > elem)
    {

        this->p[q + 1] = this->p[q];
        q--;
    }
    this->p[q + 1] = elem;
    this->length++;
}
template <typename T>
bool ArrayADT<T>::IsSorted()
{

    if (!this->p)
    {
        return true;
    }
    for (int i = 0; i < this->length - 1; i++)
    {
        if (this->p[i] > this->p[i + 1])
        {
            return false;
        }
    }
    return true;
}
template <typename T>
void ArrayADT<T>::NegativeSort()
{
    int i = 0;
    int j = this->length - 1;

    while (i < j)
    {
        while (this->p[i] < 0)
        {
            i++;
        }
        while (this->p[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(&this->p[i], &this->p[j]);
        }
    }
}
template <typename T>
void ArrayADT<T>::Merge(ArrayADT<T> *q, ArrayADT<T> *a)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < this->length && j < q->length)
    {
        if (this->p[i] < q->p[j])
        {
            a->p[k] = this->p[i];
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
    for (; i < this->length; i++)
    {
        a->p[k] = this->p[i];
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
template <typename T>
void ArrayADT<T>::Union(ArrayADT<T> *q, ArrayADT<T> *a)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < this->length && j < q->length)
    {
        if (this->p[i] < q->p[j])
        {
            a->p[k] = this->p[i];
            i++;
            k++;
        }
        else if (q->p[j] < this->p[i])
        {
            a->p[k] = q->p[j];
            j++;
            k++;
        }
        else
        {
            a->p[k] = this->p[i];
            i++;
            k++;
            j++;
        }
    }
    for (; i < this->length; i++)
    {
        a->p[k] = this->p[i];
        k++;
    }
    for (; j < q->length; j++)
    {

        a->p[k] = q->p[j];
        k++;
    }
    a->length = k;
}
template <typename T>
void ArrayADT<T>::Intersection(ArrayADT<T> *q, ArrayADT<T> *a)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < this->length && j < q->length)
    {
        if (this->p[i] < q->p[j])
        {

            i++;
        }
        else if (q->p[j] < this->p[i])
        {

            j++;
        }
        else if (this->p[i] == q->p[j])
        {
            a->p[k] = this->p[i];
            i++;
            j++;
            k++;
        }
    }
    a->length = k;
}
template <typename T>
void ArrayADT<T>::Difference(ArrayADT<T> *q, ArrayADT<T> *a)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < this->length && j < q->length)
    {

        if (this->p[i] < q->p[j])
        {
            a->p[k] = this->p[i];
            i++;
            k++;
        }
        else if (q->p[j] < this->p[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    for (; i < this->length; i++)
    {
        a->p[k] = this->p[i];
        k++;
    }
    a->length = k;
}
template <typename T>
void ArrayADT<T>::SingleMissingElem()
{
    int lo = this->p[0];
    int diff = lo - 0;

    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] - i != diff)
        {
            std::cout << i + diff << std::endl;
            return;
        }
    }
}
template <typename T>
void ArrayADT<T>::MultipleMissingElem()
{
    int diff = this->p[0] - 0;
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] - i != diff)
        {
            while (diff < this->p[i] - i)
            {
                std::cout << i + diff << std::endl;
                diff++;
            }
        }
    }
}
template <typename T>

void ArrayADT<T>::MultMissing()
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] < min)
        {
            min = this->p[i];
        }
    }
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] > max)
        {
            max = this->p[i];
        }
    }
    int A[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        A[i] = 0;
    }

    for (int i = 0; i < this->length; i++)
    {
        int a = this->p[i];
        A[a]++;
    }

    for (int i = min; i < max + 1; i++)
    {
        if (A[i] == 0)
        {
            std::cout << i << std::endl;
        }
    }
}
template <typename T>
void ArrayADT<T>::DisplayDuplicates()
{
    int lastDuplicate = -1;

    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] == this->p[i + 1] && this->p[i] != lastDuplicate)
        {
            std::cout << this->p[i] << std::endl;
            lastDuplicate = this->p[i];
        }
    }
}
template <typename T>
void ArrayADT<T>::DisplayDuplicatesCount()
{
    int j = 0;
    for (int i = 0; i < this->length - 1; i++)
    {
        if (this->p[i] == this->p[i + 1])
        {
            j = i + 1;
            while (this->p[j] == this->p[i])
            {
                j++;
            }
            std::cout << this->p[i] << " " << j - i << std::endl;
            i = j - 1;
        }
    }
}
template <typename T>
void ArrayADT<T>::DisplayDuplicatesCount2()
{
    int max = INT_MIN;

    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] > max)
        {
            max = this->p[i];
        }
    }
    int A[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        A[i] = 0;
    }

    for (int i = 0; i < this->length; i++)
    {
        int p = this->p[i];
        A[p]++;
    }

    for (int i = 0; i < max + 1; i++)
    {
        if (A[i] > 1)
        {
            std::cout << i << " " << A[i] << std::endl;
        }
    }
}
template <typename T>
void ArrayADT<T>::DisplayDuplicatesCount3()
{
    int count = 0;
    for (int i = 0; i < this->length - 1; i++)
    {
        count = 1;
        if (this->p[i] != -1)
        {
            for (int j = i + 1; j < this->length; j++)
            {
                if (this->p[j] == this->p[i])
                {
                    count++;
                    this->p[j] = -1;
                }
            }
        }
        if (count > 1)
        {
            std::cout << this->p[i] << " " << count << std::endl;
        }
    }
}
template <typename T>
void ArrayADT<T>::TwoSum(int k)
{
    int max = INT_MIN;
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] > max)
        {
            max = this->p[i];
        }
    }
    int A[max + 1];
    for (int i = 0; i < max + 1; i++)
    {
        A[i] = 0;
    }
    for (int i = 0; i < this->length; i++)
    {
        if (A[k - i] != 0)
        {
            std::cout << this->p[i] << " " << k - this->p[i] << std::endl;
        }
        int p = this->p[i];
        A[p]++;
    }
}
template <typename T>
void ArrayADT<T>::TwoSumSorted(int k)
{
    int i = 0;
    int j = this->length - 1;

    while (i < j)
    {
        if (this->p[i] + this->p[j] == k)
        {
            std::cout << this->p[i] << " " << this->p[j] << std::endl;
            i++;
            j--;
        }
        else if (this->p[i] + this->p[j] > k)
        {
            j--;
        }
        else if (this->p[i] + this->p[j] < k)
        {
            i++;
        }
    }
}
template <typename T>
std::pair<int, int> ArrayADT<T>::MaxMin()
{
    std::pair<int, int> ans;
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < this->length; i++)
    {
        if (this->p[i] > max)
        {
            max = this->p[i];
        }
        if (this->p[i] < min)
        {
            min = this->p[i];
        }
    }
    ans.first=min;
    ans.second=max;

    return ans;
}
template class ArrayADT<int>;
template class ArrayADT<double>;
template class ArrayADT<float>;