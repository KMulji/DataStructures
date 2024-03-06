#include <iostream>
#include <stack>

using ::std::stack;

class QueueStacks
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    QueueStacks();
    void Enqueue(int elem);
    int Dequeue();
};
QueueStacks::QueueStacks()
{
}

void QueueStacks::Enqueue(int elem)
{
    s1.push(elem);
}
int QueueStacks::Dequeue()
{
    int ans = -1;
    if (s2.empty())
    {
        if (s1.empty())
        {
            printf("Queue is empty");
            return -1;
        }
        else
        {
            while (!s1.empty())
            {
                int temp = s1.top();
                s1.pop();
                s2.push(temp);
            }
        }
    }
    ans = s2.top();
    s2.pop();
    return ans;
}
int main()
{
    QueueStacks qs = QueueStacks();
    for (int i = 0; i < 5; i++)
    {
        qs.Enqueue(i);
    }
    std::cout << qs.Dequeue() << std::endl;
    std::cout << qs.Dequeue() << std::endl;
    qs.Enqueue(5);
    qs.Enqueue(6);
    std::cout << qs.Dequeue() << std::endl;
    std::cout << qs.Dequeue() << std::endl;
    std::cout << qs.Dequeue() << std::endl;
    std::cout << qs.Dequeue() << std::endl;
    std::cout << qs.Dequeue() << std::endl;
    std::cout << qs.Dequeue() << std::endl;
    return 0;
}