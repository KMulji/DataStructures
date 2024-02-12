#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int val;
    struct Node *next;
};
struct LinkedList
{
    struct Node *Head;
    struct Node *Tail;
    int length;
};

struct LinkedList *Create(int A[], int n)
{
    struct LinkedList *ll = (struct LinkedList *)malloc(sizeof(struct LinkedList));

    ll->length = 0;
    ll->Head = NULL;
    ll->Tail = NULL;
    int i;
    for (i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = A[i];
        temp->next = NULL;
        if (!ll->Head || !ll->Tail)
        {
            ll->Head = temp;
            ll->Tail = temp;
        }
        else
        {
            ll->Tail->next = temp;
            ll->Tail = temp;
        }
    }
    ll->length = i;
    return ll;
}
void Display(struct LinkedList *ll)
{
    struct Node *curr = ll->Head;

    while (curr)
    {
        printf("%d\n", curr->val);

        curr = curr->next;
    }
    printf("Length is %d\n", ll->length);
}
void RecursiveDisp(struct Node *curr)
{
    if (!curr)
    {
        return;
    }
    printf("%d\n", curr->val);
    RecursiveDisp(curr->next);
}
int count(struct LinkedList *ll)
{
    return ll->length;
}
int RecursiveCount(struct Node *curr)
{
    if (!curr)
    {
        return 0;
    }
    return 1 + RecursiveCount(curr->next);
}
int Sum(struct LinkedList *ll)
{
    struct Node *curr = ll->Head;
    int sum = 0;
    while (curr)
    {
        sum += curr->val;
        curr = curr->next;
    }
    return sum;
}
int RecursiveSum(struct Node *curr)
{
    if (!curr)
    {
        return 0;
    }

    return curr->val + RecursiveSum(curr->next);
}
int MaxElement(struct LinkedList *ll)
{
    int max = -20000;

    struct Node *curr = ll->Head;

    while (curr)
    {
        if (curr->val > max)
        {
            max = curr->val;
        }
        curr = curr->next;
    }

    return max;
}
int RecursiveMax(struct Node *curr)
{
    int max = -23744;

    if (!curr)
    {
        return max;
    }
    max = RecursiveMax(curr->next);
    if (curr->val > max)
    {
        return curr->val;
    }
    return max;
}

struct Node *LinearSearch(struct LinkedList *ll, int key)
{
    struct Node *curr = ll->Head;

    while (curr)
    {
        if (curr->val == key)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
/*
    The idea is to move a node to the start each time we find it
*/

struct Node *LinearSearch2(struct LinkedList *ll, int key)
{
    struct Node *curr = ll->Head;
    struct Node *prev = NULL;

    while (curr)
    {
        if (curr->val == key)
        {
            if (curr != ll->Head)
            {
                prev->next = curr->next;
                curr->next = ll->Head;
                ll->Head = curr;
                return prev;
            }
            else
            {
                return curr;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return NULL;
}
void Append(int elem, struct LinkedList *ll)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;
    if (!ll->Head || !ll->Tail)
    {
        ll->Head = temp;
        ll->Tail = temp;
        return;
    }
    ll->Tail->next = temp;
    ll->Tail = temp;
}
void Push(int elem, struct LinkedList *ll)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;
    if (!ll->Head || !ll->Tail)
    {

        ll->Head = temp;
        ll->Tail = temp;
        return;
    }
    temp->next = ll->Head;
    ll->Head = temp;
}
void Insert(int index, int elem, struct LinkedList *ll)
{
    if (index < 0 || index >= ll->length+1)
    {
        printf("out of index\n");
        return;
    }
    struct Node *p = ll->Head;

    if (index == 0)
    {
        // put to head
        Push(elem, ll);
    }
    else if (index == ll->length)
    {
        // append
        Append(elem, ll);
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = elem;
        temp->next = p->next;
        p->next = temp;
    }
    ll->length++;
}
void InsertSorted(int elem, struct LinkedList *ll)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = elem;

    if (!ll->Head || !ll->Tail)
    {
        ll->Head = temp;
        ll->Tail = temp;
        ll->length++;
        return;
    }
    if (elem <= ll->Head->val)
    {
        temp->next = ll->Head;
        ll->Head = temp;
        return;
    }
    if (elem >= ll->Tail->val)
    {
        ll->Tail->next = temp;
        ll->Tail = temp;
        return;
    }
    struct Node *p = ll->Head;
    struct Node *q = NULL;

    while (p)
    {
        if (p->val > elem)
        {
            break;
        }
        q = p;
        p = p->next;
    }

    temp->next = q->next;
    q->next = temp;
    ll->length++;
}
int Delete(int index, struct LinkedList *ll)
{
    int ans = 0;
    if (index < 0 || index >= ll->length)
    {
        printf("No Such Index\n");
        return -1;
    }
    if (!ll->Head || !ll->Tail)
    {
        printf("List is empty");
        return -1;
    }
    if (index == 0)
    {
        struct Node *temp = ll->Head;
        ll->Head = ll->Head->next;
        ll->length--;
        ans = temp->val;
        free(temp);
        return ans;
    }
    struct Node *q = NULL;
    struct Node *p = ll->Head;

    for (int i = 0; i < index; i++)
    {
        q = p;
        p = p->next;
    }
    ans = p->val;
    q->next = p->next;
    p->next = NULL;
    ll->length--;
    free(p);
}
int CheckSorted(struct LinkedList *ll)
{
    struct Node *curr = ll->Head;

    while (curr && curr->next)
    {
        if (curr->val > curr->next->val)
        {
            return 0;
        }
        curr = curr->next;
    }
    return 1;
}
void RemoveDuplicates(struct LinkedList *ll)
{
    if (!ll->Head)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *p = ll->Head;
    struct Node *q = ll->Head->next;

    while (p && q)
    {
        if (p->val == q->val)
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}
void Reverse(struct LinkedList *ll)
{
    struct Node *k = ll->Head;
    struct Node *i = NULL;
    struct Node *j = NULL;

    while (k)
    {
        i = j;
        j = k;
        k = k->next;

        j->next = i;
    }
    ll->Tail = ll->Head;
    ll->Head = j;
}
void RecursiveReverse(struct Node *p, struct Node *q, struct LinkedList *ll)
{
    if (!p)
    {
        ll->Tail = ll->Head;
        ll->Head = q;
    }
    else
    {
        RecursiveReverse(p->next, p, ll);
        p->next = q;
    }
}
struct LinkedList *Merge(struct LinkedList *ll1, struct LinkedList *ll2)
{
    struct Node *first = ll1->Head;
    struct Node *second = ll2->Head;
    struct Node *third = NULL;
    struct Node *last = NULL;

    if (first->val < second->val)
    {
        third = first;
        last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = second;
        last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first && second)
    {
        if (first->val < second->val)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }
    if (first)
    {
        last->next = first;
    }
    if (second)
    {
        last->next = second;
    }
    struct LinkedList *ll3 = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    ll3->length = ll1->length + ll2->length;
    ll3->Head = third;
    struct Node *curr = ll3->Head;
    while (curr->next)
    {
        curr = curr->next;
    }
    ll3->Tail = curr;
    return ll3;
}
int HasCycle(struct LinkedList *ll)
{
    struct Node *slow = ll->Head;
    struct Node *fast = ll->Head;

    while (fast)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int A[] = {1};
    struct LinkedList* ll = Create(A,1);

    Delete(0,ll);
    return 0;
}
