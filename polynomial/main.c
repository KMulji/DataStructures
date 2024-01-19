
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
        sum += (double)p->t[i].coeff * pow(base, expo);
    }
    return sum;
}
struct Polynomial *Add(struct Polynomial *p1, struct Polynomial *p2)
{
    // point to p1
    int i = 0;
    // point to p2
    int j = 0;
    // point to p3
    int k = 0;

    // return poly
    struct Polynomial *p3 = (struct Polynomial *)malloc(sizeof(struct Polynomial));

    p3->t = (struct Term *)malloc((p1->num) + (p2->num) * sizeof(struct Term));

    while (i < p1->num && i < p2->num)
    {
        if (p1->t[i].exp > p2->t[j].exp)
        {
            p3->t[k] = p1->t[i];
            i++;
            k++;
        }
        else if (p2->t[j].exp > p1->t[i].exp)
        {
            p3->t[k] = p2->t[j];
            j++;
            k++;
        }
        else if (p1->t[i].exp == p2->t[j].exp)
        {
            p3->t[k] = p1->t[i];
            p3->t[k].coeff = p1->t[i].coeff + p2->t[j].coeff;
            p3->t[k].exp = p1->t[i].exp;
            k++;
            i++;
            j++;
        }
    }
    // copy remaining elements;
    for (; i < p1->num; i++)
    {
        p3->t[k] = p1->t[i];
        k++;
    }
    for (; j < p2->num; j++)
    {
        p3->t[k] = p2->t[j];

        k++;
    }
    // set p3 size to k
    p3->num=k;
    return p3;
}
int main()
{
    struct Polynomial p1;
    struct Polynomial p2;
    Create(&p1);
    Create(&p2);
    printf("P1 is\n");
    Display(&p1);
    printf("P2 is \n");
    Display(&p2);
    struct Polynomial* p3 = Add(&p1,&p2);
    Display(p3);
    return 0;
}