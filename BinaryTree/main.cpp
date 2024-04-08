#include <iostream>
#include <queue>
#include <stack>
#include <cstdint>
using std::queue;
using std::stack;
struct Node
{
    int Data;
    struct Node *left;
    struct Node *right;
};
struct BinaryTree
{
    struct Node *Root;
};

struct BinaryTree *Create()
{
    struct BinaryTree *bt = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    queue<struct Node *> qt;
    struct Node *temp;
    struct Node *p;
    int x;
    std::cout << "Enter Value of root";
    std::cin >> x;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->Data = x;
    temp->left = NULL;
    temp->right = NULL;
    bt->Root = temp;

    qt.push(temp);

    while (!qt.empty())
    {
        p = qt.front();
        qt.pop();

        std::cout << "Does " << p->Data << "Have a left node";
        std::cin >> x;

        if (x != -1)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->Data = x;
            temp->left = NULL;
            temp->right = NULL;
            p->left = temp;
            qt.push(temp);
        }
        std::cout << "Does " << p->Data << "Have a right node";
        std::cin >> x;

        if (x != -1)
        {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->Data = x;
            temp->left = NULL;
            temp->right = NULL;
            p->right = temp;
            qt.push(temp);
        }
    }
    return bt;
}
void PreOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    std::cout << root->Data << std::endl;
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    std::cout << root->Data << std::endl;
    InOrder(root->right);
}
void PostOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    std::cout << root->Data << std::endl;
}
void PostOrderIterative(struct Node *t)
{
    stack<long long int> st;
    long long int temp;

    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {

            st.push(reinterpret_cast<long long int>(t));
            t = t->left;
        }
        else
        {
            long long int temp = st.top();
            st.pop();
            if (temp > 0)
            {
                st.push(reinterpret_cast<long long int>(-temp));
                t = reinterpret_cast<struct Node *>(temp)->right;
            }
            else
            {
                temp = -temp;
                std::cout << reinterpret_cast<struct Node *>(temp)->Data << std::endl;
                t = NULL;
            }
        }
    }
}
void PreorderIterative(struct Node *t)
{
    stack<Node *> st;
    st.push(t);

    while (!st.empty() || t == NULL)
    {
        if (t != NULL)
        {
            std::cout << t->Data << std::endl;
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            t = t->right;
        }
    }
}
void InorderIterative(struct Node *t)
{
    stack<Node *> st;
    while (t != NULL || !st.empty())
    {
        if (t != NULL)
        {
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();
            std::cout << t->Data << std::endl;
            t = t->right;
        }
    }
}
int CountLeaf(struct Node *t)
{
    if (!t)
    {
        return 0;
    }
    if (!t->left && !t->right)
    {
        return 1;
    }
    return CountLeaf(t->left) + CountLeaf(t->right);
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
void LevelOrder(struct Node *t)
{
    queue<Node *> qt;
    qt.push(t);
    while (!qt.empty())
    {
        struct Node *temp = qt.front();
        qt.pop();
        std::cout << temp->Data << std::endl;
        if (temp->left)
        {
            qt.push(temp->left);
        }
        if (temp->right)
        {
            qt.push(temp->right);
        }
    }
}
int count(struct Node *t)
{
    if (!t)
    {
        return 0;
    }
    int left = count(t->left);
    int right = count(t->right);

    return 1 + left + right;
}
int rootLeafPaths(struct Node *t)
{
    
}
int main()
{
    struct BinaryTree *bt = Create();
    std::cout << count(bt->Root) << std::endl;

    return 0;
}
