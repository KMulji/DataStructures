#include <iostream>
#include <stack>
#include <string>
using std::stack;
using std::string;
bool isOperand(char x)
{
    if (x == '+' || x == '/' || x == '*' || x == '-')
    {
        return false;
    }
    return true;
}
int Prec(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    return 0;
}
string Post(string temp)
{
    stack<char> st;
    string ans = "";

    int i = 0;

    while (i < temp.size())
    {
        char temp3 = temp[i];
        if (isOperand(temp[i]))
        {
            ans.push_back(temp[i]);
            i++;
        }
        else
        {
            if (st.empty())
            {
                st.push(temp[i]);
                i++;
            }
            else if (Prec(temp[i]) > Prec(st.top()))
            {
                st.push(temp[i]);
                i++;
            }
            else if (Prec(temp[i]) <= Prec(st.top()))
            {
                char temp2 = st.top();
                st.pop();
                ans.push_back(temp2);
            }
        }
    }
    while (!st.empty())
    {
        char temp = st.top();
        ans.push_back(temp);
        st.pop();
    }

    return ans;
}
int Evaluate(string in)
{
    stack<int> st;
    int x1 = -1;
    int x2 = -1;
    int r = 0;
    for (int i = 0; i < in.size(); i++)
    {
        if (isOperand(in[i]))
        {
            st.push(in[i] - '0');
        }
        else
        {

            x2 = st.top();
            st.pop();
            x1 = st.top();
            st.pop();
            if (in[i] == '+')
            {
                r = x1 + x2;
            }
            else if (in[i] == '-')
            {
                r = x1 - x2;
            }
            else if (in[i] == '*')
            {
                r = x1 * x2;
            }
            else if (in[i] == '/')
            {
                r = x1 / x2;
            }
            st.push(r);
        }
    }
    return st.top();
}
int main()
{
    string example = "234*+82/-";

        int eval = Evaluate(example);
    std::cout << eval << std::endl;

    return 0;
}