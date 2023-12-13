#include <iostream>
#include "ArrayADT.hpp"
int main()
{
    ArrayADT<int> a = ArrayADT<int>();

    a.Append(1);
    a.Append(3);
    a.Append(4);
    a.Append(5);
    a.Append(6);
    a.Append(8);
    a.Append(9);
    a.Append(10);
    a.Append(12);
    a.Append(14);
    a.TwoSumSorted(10);

    return 0;
}