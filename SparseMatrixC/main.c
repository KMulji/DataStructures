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
    scanf("%d%d",&s->m,&s->n);
    printf("Enter number of nonzero");
    scanf("%d",&s->num);

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

int main()
{

    struct Sparse s;
    create(&s);
    display(&s);
    return 0;
}