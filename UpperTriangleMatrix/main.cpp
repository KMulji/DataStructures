#include <iostream>

class UpperTriangle
{
private:
    int *a;
    int n;

public:
    UpperTriangle(int n);
    void Set(int i, int j, int elem);
    int Get(int i, int j, int elem);
    void ColSet(int i, int j, int elem);
    int ColGet(int i, int j, int elem);
    void Display();
    void ColDisplay();
    ~UpperTriangle();
};
UpperTriangle::UpperTriangle(int n)
{
    this->n = n;
    this->a = new int[n * (n + 1) / 2];
}
void UpperTriangle::Set(int i, int j, int elem)
{
    if (i <= j)
    {
        int index = (n * (i - 1)) - (((i - 2) * (i - 1)) / 2);
        this->a[index] = elem;
    }
}

void UpperTriangle::Display()
{
    for (int i = 1; i < this->n; i++)
    {
        for (int j = 1; j < this->n; j++)
        {
            if (i <= j)
            {
                int index = (n * (i - 1)) - (((i - 2) * (i - 1)) / 2);
                std::cout << this->a[index] << " ";
            }
            else
            {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}
int UpperTriangle::Get(int i, int j, int elem)
{
    if (i <= j)
    {
        int index = (n * (i - 1)) - (((i - 2) * (i - 1)) / 2);
        return this->a[index];
    }
    return 0;
}
void UpperTriangle::ColSet(int i, int j, int elem)
{
    if (i <= j)
    {
        int index = (j * (j - 1) / 2) + (i - j);
        this->a[index] = elem;
    }
}
int UpperTriangle::ColGet(int i, int j, int elem)
{
    if (i <= j)
    {
        int index = (j * (j - 1) / 2) + (i - j);
        return this->a[index];
    }
    return 0;
}

void UpperTriangle::ColDisplay()
{
    for(int i=1;i<this->n;i++){
        for(int j=1;j<this->n;j++){
            if(i<=j){
                int index = (j*(j-1)/2)+(i-j);
                std::cout<<this->a[index]<<" ";
            }else{
                std::cout<<"0 ";
            }
            
        }
        std::cout<<std::endl;
    }
}

UpperTriangle::~UpperTriangle()
{
    delete[] this->a;
}
int main()
{
    UpperTriangle T(5);
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            T.ColSet(i, j, i);
        }
    }
    T.ColDisplay();
    return 0;
}