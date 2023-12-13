#include <iostream>
#include "ArrayADT.hpp"
int main()
{
    ArrayADT<int> a = ArrayADT<int>();
    a.Append(3);
    a.Append(6);
    a.Append(8);
    a.Append(8);
    a.Append(10);
    a.Append(12);
    a.Append(15);
    a.Append(15);
    a.Append(15);
    a.Append(15);
    a.Append(20);
    

    a.DisplayDuplicatesCount3();

    return 0;
}