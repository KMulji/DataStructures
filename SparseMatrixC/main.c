#include <stdlib.h>
#include <stdio.h>
struct Element
{
    // element row number
    int i;
    // element col number
    int j;
    // element value
    int x;
};
struct Sparse
{
    // no of rows
    int m;
    // no of columns
    int n;
    // num of nonzero
    int num;
    // array of elements
    struct Element *e;

    
};
void create(struct Sparse *s)
{
    printf("Enter number of rows and columns");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter number of nonzero");
    scanf("%d", &s->num);

    s->e = (struct Element *)malloc(s->num * sizeof(struct Element));

    for (int i = 0; i < s->num; i++)
    {
        scanf("%d%d%d", &s->e[i].i, &s->e[i].j, &s->e[i].x);
    }
}
void display(struct Sparse *s)
{
    int k = 0;
    for (int i = 0; i < s->m; i++)
    {
        for (int j = 0; j < s->n; j++)
        {
            if (s->e[k].i == i && s->e[k].j == j)
            {
                printf("%d ", s->e[k++].x);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
struct Sparse *Add(struct Sparse *s1, struct Sparse *s2)
{
    // dimensions not the same
    if (s1->m != s2->m || s1->n != s2->n)
    {
        return NULL;
    }
    // point to s1
    int i = 0;
    // point to s2
    int j = 0;
    // point to sum
    int k = 0;
    struct Sparse *sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->m = s1->m;
    sum->n = s1->n;

    sum->e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i < s1->num && j < s2->num)
    {
        // if s1 row < s2 row -> copy element in s1
        if (s1->e[i].i < s2->e[j].i)
        {
            sum->e[k] = s1->e[i];
            k++;
            i++;
            // if s2 row< s1 row -> copy element in s2.
        }
        else if (s2->e[j].i < s1->e[i].i)
        {
            sum->e[k] = s2->e[j];
            k++;
            j++;
        }
        else
        {
            // if s1 col < s2 col, copy element in s1
            if (s1->e[i].j < s2->e[j].j)
            {
                sum->e[k] = s1->e[i];
                i++;
                k++;
                // if s2 col < s1 col copy element in s2
            }
            else if (s2->e[j].j < s1->e[i].j)
            {
                sum->e[k] = s2->e[j];
                j++;
                k++;
                // we know now s1 row and col are equal do sum
            }
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k].x = s1->e[i].x + s2->e[j].x;
                k++;
                i++;
                j++;
            }
        }
    } 
    // since j may finish before i we need to copy the remaining ones
    for (; i < s1->num; i++)
    {
        sum->e[k] = s1->e[i];
        k++;
    }
    // since i may finish before j we need to copy the remaining ones.
    for (; j < s2->num; j++)
    {
        sum->e[k] = s2->e[j];
        k++;
    }

    sum->num = k;

    return sum;
}
int main()
{

    struct Sparse s1;
    struct Sparse s2;
    create(&s1);
    create(&s2);

    struct Sparse *s3 = Add(&s1, &s2);
    display(s3);
    return 0;
}