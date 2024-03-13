#include <iostream>
#include <queue>

using std::queue;

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
int main()
{
    struct BinaryTree *bt = Create();
    PreOrder(bt->Root);
    std::cout<<" "<<std::endl;
    InOrder(bt->Root);
    std::cout<<" "<<std::endl;
    PostOrder(bt->Root);
    std::cout<<" "<<std::endl;
    return 0;
}