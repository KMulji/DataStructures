#include <stdlib.h>
#include <stdio.h>
#include "ArrayADT.h"
int main()
{
    printf("Welcome to Array ADT in C\n");
    printf("Options -> \n");
    printf("1. Append\n");
    printf("2. Insert at a index\n");
    printf("3. Delete at a index\n");
    printf("4. Display elements\n");
    printf("5. Display size and length.\n");

    struct ArrayADT *p = InitH(5);
    int n;
    int elem;
    int idx;
    do
    {
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            printf("Enter a number to append\n");
            scanf("%d", &elem);
            Append(p, elem);
            break;
        case 2:
            printf("Enter a number and index to insert\n");
            scanf("%d%d", &elem, &idx);
            Insert(p, idx, elem);
            break;
        case 3:
            printf("Enter a index to delete\n");
            scanf("%d", &idx);
            Delete(p, idx);
            break;
        case 4:
            Display(p);
            break;
        case 5:
            printf("Size is %d, length is %d\n",p->size,p->length);
            break;
        default:
            break;
        }
    } while (n != 7);

    return 0;
}