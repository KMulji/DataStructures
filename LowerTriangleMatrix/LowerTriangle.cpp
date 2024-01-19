#include <iostream>
class LowerTriangle
{
private:
    int *a;
    int n;

public:
    LowerTriangle(int n);
    int Get(int i, int j);
    int ColGet(int i, int j);
    void ColSet(int i, int j, int elem);
    void Set(int elem, int i, int j);
    void Display();
    void ColDisplay();
    ~LowerTriangle();
};
LowerTriangle::LowerTriangle(int n)
{
    this->n = n;
    this->a = new int[(n * (n + 1)) / 2];
}
int LowerTriangle::Get(int i, int j)
{
    if (i >= j)
    {
        int index = ((i * (i - 1)) / 2) + (j - 1);
        return this->a[index];
    }
    return 0;
}
void LowerTriangle::Set(int elem, int i, int j)
{
    if (i >= j)
    {
        int index = ((i * (i - 1)) / 2) + (j - 1);
        this->a[index] = elem;
    }
}
LowerTriangle::~LowerTriangle()
{
    delete[] this->a;
}
void LowerTriangle::Display()
{
    for (int i = 1; i < this->n; i++)
    {
        for (int j = 1; j < this->n; j++)
        {
            if (i >= j)
            {
                int index = ((i * (i - 1)) / 2) + (j - 1);
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
void LowerTriangle::ColDisplay()
{
    for (int i = 1; i < this->n; i++)
    {
        for (int j = 1; j < this->n; j++)
        {
            if (i >= j)
            {
                int index = (this->n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
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
int LowerTriangle::ColGet(int i, int j)
{
    if (i >= j)
    {
        int index = (this->n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        return this->a[index];
    }
    return 0;
}
void LowerTriangle::ColSet(int i, int j, int elem)
{
    if (i >= j)
    {
        int index = (this->n * (j-1) - (((j-2) * (j-1))/2)) + (i-j);
        this->a[index] = elem;
    }
}
int main()
{
    LowerTriangle T(5);
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            if (i >= j)
            {
                T.ColSet(i, j, i);
            }
        }
    }
    T.ColDisplay();
    return 0;
}