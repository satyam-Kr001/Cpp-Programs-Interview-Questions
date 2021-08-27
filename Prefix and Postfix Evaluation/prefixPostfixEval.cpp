#include <bits/stdc++.h>
using namespace std;

void prefixEvaluation(string s)
{
    stack<int> stk;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            stk.push(s[i] - '0');
        }

        else
        {
            int op1 = stk.top();
            stk.pop();
            int op2 = stk.top();
            stk.pop();

            switch (s[i])
            {
            case '+':
                stk.push(op1 + op2);
                break;
            case '-':
                stk.push(op1 - op2);
                break;
            case '*':
                stk.push(op1 * op2);
                break;
            case '/':
                stk.push(op1 / op2);
                break;
            }
        }
    }

    cout << stk.top() << endl;
}

void postfixEvaluation(string s)
{
    stack<int> stk;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' and s[i] <= '9')
        {
            stk.push(s[i] - '0');
        }

        else
        {
            int op2 = stk.top();
            stk.pop();
            int op1 = stk.top();
            stk.pop();

            switch (s[i])
            {
            case '+':
                stk.push(op1 + op2);
                break;
            case '-':
                stk.push(op1 - op2);
                break;
            case '*':
                stk.push(op1 * op2);
                break;
            case '/':
                stk.push(op1 / op2);
                break;
            }
        }
    }

    cout << stk.top() << endl;
}

int main()
{
    string s1 = "-+7*45+20";
    string s2 = "46+2/5*7+";
    // prefixEvaluation(s1);
    postfixEvaluation(s2);
}