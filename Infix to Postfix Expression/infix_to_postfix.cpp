#include <bits/stdc++.h>
using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' or c == '/')
        return 2;
    else if (c == '+' or c == '-')
        return 1;
    else
        return -1;
}

void infixTOPostfix(string s)
{
    stack<char> stk;
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(s[i]);
        }

        else if ((s[i] >= 'a' and s[i] <= 'z') or (s[i] >= 'A' and s[i] <= 'Z'))
        {
            res += s[i];
        }

        else if (s[i] == ')')
        {
            while (!stk.empty() and stk.top() != '(')
            {
                res += stk.top();
                stk.pop();
            }
            if (!stk.empty())
            {
                stk.pop();
            }
        }

        else
        {
            while (!stk.empty() and precedence(stk.top()) > precedence(s[i]))
            {
                res += stk.top();
                stk.pop();
            }
            stk.push(s[i]);
        }
    }
    while (!stk.empty())
    {
        res += stk.top();
        stk.pop();
    }
    cout << res << endl;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";
    infixTOPostfix(s);
}