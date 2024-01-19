
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct Term
{
    // represent exponent
    int exp;
    // represent coefficient
    int coeff;
};

struct Polynomial
{
    // number of terms
    int num;
    // array of terms
    struct Term *t;
};

void Create(struct Polynomial *p)
{
    printf("Enter number of terms");
    scanf("%d", &p->num);
    p->t = (struct Term *)malloc(p->num * sizeof(struct Term));
    for (int i = 0; i < p->num; i++)
    {
        scanf("%d%d", &p->t[i].coeff, &p->t[i].exp);
    }
}
void Display(struct Polynomial *p)
{
    for (int i = 0; i < p->num; i++)
    {
        printf("%dx^%d + ", p->t[i].coeff, p->t[i].exp);
    }
    printf("\n");
}
double Eval(struct Polynomial *p, double val)
{
    double sum = 0;
    for (int i = 0; i < p->num; i++)
    {
        double base = val;
        double expo = p->t[i].exp;
        sum += (double)p->t[i].exp * pow(base, expo);
    }
    return sum;
}
int main()
{
    struct Polynomial p;
    Create(&p);

    Display(&p);
    Eval(&p, 2);
    return 0;
}