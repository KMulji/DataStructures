#include <iostream>
#include "ArrayADT.hpp"
int main()
{
    ArrayADT<int> a = ArrayADT<int>();

    a.Append(5);
    a.Append(8);
    a.Append(3);
    a.Append(9);
    a.Append(6);
    a.Append(2);
    a.Append(10);
    a.Append(7);
    a.Append(-1);
    a.Append(4);
    a.MaxMin();

    return 0;
}