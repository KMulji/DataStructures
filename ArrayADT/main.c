#include <stdlib.h>
#include <stdio.h>
#include "ArrayADT.h"
int main()
{
    // struct ArrayADT *p = InitH(5);
    // int n;
    // int elem;
    // int idx;
    // do
    // {
    //     scanf("%d", &n);

    //     switch (n)
    //     {
    //     case 1:
    //         printf("Enter a number to append\n");
    //         scanf("%d", &elem);
    //         Append(p, elem);
    //         break;
    //     case 2:
    //         printf("Enter a number and index to insert\n");
    //         scanf("%d%d", &elem, &idx);
    //         Insert(p, idx, elem);
    //         break;
    //     case 3:
    //         printf("Enter a index to delete\n");
    //         scanf("%d", &idx);
    //         Delete(p, idx);
    //         break;
    //     case 4:
    //         Display(p);
    //         break;
    //     case 5:
    //         printf("Size is %d, length is %d\n",p->size,p->length);
    //         break;
    //     default:
    //         break;
    //     }
    // } while (n != 7);

    struct ArrayADT *p = InitH(20);
    struct ArrayADT *q = InitH(20);
    Append(p,3);
    Append(p,4);
    Append(p,5);
    Append(p,6);
    Append(p,10);
    
    Append(q,2);
    Append(q,4);
    Append(q,5);
    Append(q,7);
    Append(q,12);

    struct ArrayADT *z = InitH(p->size+q->size);
    Intersection(p,q,z);
    Display(p);
    Display(q);
    Display(z);
    return 0;
}