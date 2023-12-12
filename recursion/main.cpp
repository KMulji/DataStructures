#include <iostream>
#include <unordered_map>
using std::unordered_map;
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
int fact(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    return fact(n - 1) * n;
}
/*
    Write a recursive function to calculate power m^n
*/
int pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return pow(m, n - 1) * m;
}
/*Write a recursive function for taylor series of e^x*/
double e(int x, int n)
{
    static int p = 0;
    static int f = 1;
    double r;
    if (n == 0)
    {
        return 1;
    }

    r = e(x, n - 1);
    p = p * x;
    f = f * n;
    return r + p / f;
}
/*Write a iterative and recursive function for taylor series with horners rule optimization*/
double eh(int x, int n)
{
    double s = 1;
    for (; n > 0; n--)
    {
        s = 1 + x / n * s;
    }
    return s;
}
double ehr(int x, int n)
{
    static int s = 1;

    if (n == 0)
    {
        return s;
    }
    s = 1 + x / n * s;

    return e(x, n - 1);
}
int fib(int n)
{
    static unordered_map<int, int> mp;
    if (n == 0)
    {
        mp[n] = 0;
    }
    else if (n == 1)
    {
        mp[n] = 1;
    }
    else
    {
        mp[n] = fib(n - 2) + fib(n - 1);
    }

    return mp[n];
}
int iterativeFib(int n){
    int f0=0;
    int f1=1;
    int sum;
    for(int i=2;i<=n;i++){
        sum=f0+f1;
        f0=f1;
        f1=sum;
    }
    return sum;
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
    std::cout << iterativeFib(10) << std::endl;
    return 0;
}