#include <iostream>
#include "ArrayADT.hpp"
int main()
{
    ArrayADT<int> a = ArrayADT<int>();
    ArrayADT<int> b = ArrayADT<int>();
    ArrayADT<int> c = ArrayADT<int>();
    a.Append(3);
    a.Append(4);
    a.Append(5);
    a.Append(6);
    a.Append(10);

    b.Append(2);
    b.Append(4);
    b.Append(5);
    b.Append(7);
    b.Append(12);

    a.Difference(&b,&c);
    a.Display();
    b.Display();
    c.Display();

    return 0;
}