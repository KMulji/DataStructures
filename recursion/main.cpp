#include <iostream>
void fun1(int n)
{
    if (n == 0)
    {

        return;
    }

    std::cout << n << std::endl;
    fun1(n - 1);
}
int fun2(int n)
{
    static int x = 0;
    if (n == 0)
    {
        return 0;
    }
    x++;
    return fun2(n - 1) + x;
}
/*
    Write a recursive function to calculate the sum of
    the first n numbers;
*/
int sum(int n)
{
    if (n == 0)
        return 0;
    
    return sum(n - 1) + n;
}
/*
    Write a recursive function to calculate the factorial of n.
*/
int fact(int n){
    if(n<=0){
        return 1;
    }
    return fact(n-1)*n;
}
/*
    Write a function to determine combinations.
*/
int combination(int n,int r){
    if(r==0||n==r){
        return 1;
    }
    return combination(n-1,r-1)+combination(n-1,r);
}
/*
    Write a function for tower of hanoi problem.
*/
void TOH(int n,int A,int B, int C){
    if(n==0){
        return;
    }
    TOH(n-1,A,C,B);
    std::cout<<"From "<<A<<" To "<<C<<std::endl;
    TOH(n-1,B,A,C);
}
int main()
{
    std::cout<<fact(3)<<std::endl;
    return 0;
}