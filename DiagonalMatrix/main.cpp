#include <iostream>
#include <stdlib.h>
class DiagonalMatrix
{
private:
    int *a;
    int n;

public:
    DiagonalMatrix();
    DiagonalMatrix(int n);
    void set(int i, int j, int elem);
    int get(int i, int j);
    void Display();
    ~DiagonalMatrix();
};
DiagonalMatrix::DiagonalMatrix()
{
    this->n = 5;
    this->a = new int[5];
}
DiagonalMatrix::DiagonalMatrix(int n)
{
    this->n = n;
    this->a = new int[n];
}
DiagonalMatrix::~DiagonalMatrix()
{
    delete[] a;
}
void DiagonalMatrix::set(int i, int j, int elem)
{
    if (i == j)
    {
        this->a[i] = elem;
    }
}
int DiagonalMatrix::get(int i, int j)
{
    if (i == j)
    {
        return this->a[i];
    }
    return 0;
}
void DiagonalMatrix::Display()
{
    for(int i=0;i<this->n;i++){
        for(int j=0;j<this->n;j++){
            if(i==j){
                std::cout<<this->a[i]<<" ";
            }else{
                std::cout<<0<<" ";
            }
        }
        std::cout<<std::endl;
    }
}
int main()
{
    DiagonalMatrix D(4);
    D.set(0,0,5);
    D.set(1,1,8);
    D.set(2,2,9);
    D.set(3,3,12);
    D.Display();

    std::cout<<D.get(3,3)<<std::endl;
    return 0;
}