#include <iostream>
#include <stack>

using std::stack;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct BST
{
    struct Node *Root;
};

struct BST *Create()
{
    int x;
    struct BST *b = (struct BST *)malloc(sizeof(struct BST));
    std::cout << "Enter Root Value";
    std::cin >> x;

    // Create Root.
    struct Node *temp = (struct Node *)malloc(sizeof(struct BST));
    temp->data = x;
    b->Root = temp;

    struct Node *t = b->Root;
    struct Node *r = NULL;
    bool Present = false;
    while (x != -1)
    {
        std::cout << "Enter next node value";
        std::cin >> x;
        t = b->Root;
        while (t != NULL)
        {
            r = t;
            if (t->data == x)
            {
                std::cout << "Already Present" << std::endl;
                Present = true;
                t = NULL;
            }
            else if (x > t->data)
            {
                t = t->right;
                Present = false;
            }
            else if (x < t->data)
            {
                t = t->left;
                Present = false;
            }
        }
        if (!Present && x != -1)
        {
            temp = (struct Node *)malloc(sizeof(struct BST));
            temp->data = x;

            if (x > r->data)
            {
                r->right = temp;
            }
            else if (x < r->data)
            {
                r->left = temp;
            }
        }
    }
    return b;
}

void InOrder(struct Node *t)
{
    if (!t)
    {
        return;
    }
    InOrder(t->left);
    std::cout << t->data << std::endl;
    InOrder(t->right);
}
struct Node *Search(struct Node *t, int key)
{
    while (t != NULL)
    {
        if (t->data == key)
        {
            return t;
        }
        else if (key > t->data)
        {
            t = t->right;
        }
        else if (key < t->data)
        {
            t = t->left;
        }
    }
    return NULL;
}
void RInsert(struct Node *r, struct Node *t, int val)
{
    if (!t)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = val;
        if (val < r->data)
        {
            r->left = temp;
        }
        if (val > r->data)
        {
            r->right = temp;
        }
        return;
    }
    if (t->data == val)
    {
        return;
    }
    if (val < t->data)
    {
        RInsert(r = t, t->left, val);
    }
    else if (val > t->data)
    {
        RInsert(r = t, t->right, val);
    }
}
struct Node *RSearch(struct Node *t, int key)
{
    if (!t)
    {
        return NULL;
    }
    else if (key == t->data)
    {
        return t;
    }
    else if (key > t->data)
    {
        return RSearch(t->right, key);
    }
    return RSearch(t->left, key);
}

void Insert(struct Node *t, int val)
{
    if (!t)
    {
        return;
    }
    struct Node *r = NULL;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = val;
    while (t != NULL)
    {
        r = t;
        if (val == t->data)
        {
            std::cout << "Already in the tree" << std::endl;
            return;
        }
        else if (val < t->data)
        {
            t = t->left;
        }
        else if (val > t->data)
        {
            t = t->right;
        }
    }
    if (val < r->data)
    {
        r->left = temp;
    }
    else if (val > r->data)
    {
        r->right = temp;
    }
}
int Height(struct Node *t)
{
    if (!t)
    {
        return 0;
    }
    int x = Height(t->left);
    int y = Height(t->right);

    if (x > y)
    {
        return x + 1;
    }
    return y + 1;
}
struct Node *InPre(struct Node *t)
{

    while (t && t->right)
    {
        t = t->right;
    }
    return t;
}
struct Node *InSucc(struct Node *t)
{

    while (t && t->left)
    {
        t = t->left;
    }
    return t;
}
struct Node *Delete(struct Node *r, int key)
{
    if (!r)
    {
        return NULL;
    }
    if (!r->left && !r->right)
    {
        r->left = NULL;
        r->right = NULL;
        free(r);
        return NULL;
    }
    if (key < r->data)
    {
        r->left = Delete(r->left, key);
    }
    else if (key > r->data)
    {
        r->right = Delete(r->right, key);
    }
    else
    {

        if (Height(r->left) > Height(r->right))
        {
            struct Node *q = InPre(r->left);
            r->data = q->data;
            r->left = Delete(r->left, q->data);
        }
        else
        {
            struct Node *q = InSucc(r->right);
            r->data = q->data;
            r->right = Delete(r->right, q->data);
        }
    }
    return r;
}
/*
    Generate BST from a given pre order traversal
*/
struct BST *Generate(int pre[], int n)
{
    struct BST *bt = (struct BST *)malloc(sizeof(struct BST));
    int i = 0;
    struct Node *t;
    stack<long long int> st;
    // create root
    struct Node *r = (struct Node *)malloc(sizeof(struct Node));
    r->data = pre[0];
    r->left = NULL;
    r->right = NULL;
    bt->Root = r;
    r = NULL;
    t = bt->Root;
    st.push(reinterpret_cast<long long int>(t));
    i = 1;
    while (i < n)
    {
        // if its less put on left side.
        if (pre[i] < t->data)
        {
            r = (struct Node *)malloc(sizeof(struct Node));
            r->data = pre[i];
            i++;
            r->left = NULL;
            r->right = NULL;
            t->left = r;
            st.push(reinterpret_cast<long long int>(t));
            t = r;
            r = NULL;
        }
        // 
        else
        {
            //
            if (pre[i] > t->data && st.empty())
            {
                r = (struct Node *)malloc(sizeof(struct Node));
                r->data = pre[i];
                r->left = NULL;
                r->right = NULL;
                i++;
                t->right = r;
                t = r;
                r = NULL;
            }
            //
            else if (pre[i] > t->data && pre[i] < reinterpret_cast<struct Node *>(st.top())->data)
            {
                r = (struct Node *)malloc(sizeof(struct Node));
                r->data = pre[i];
                r->left = NULL;
                r->right = NULL;
                i++;
                t->right = r;
                t = r;
                r = NULL;
            }
            //
            else
            {
                t = reinterpret_cast<struct Node *>(st.top());
                st.pop();
            }
        }
    }

    return bt;
}
int main()
{
    int a[] = {30, 20, 10, 15, 25, 40, 50, 45};
    struct BST *bt = Generate(a, 8);
    InOrder(bt->Root);
    return 0;
}