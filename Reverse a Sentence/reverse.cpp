#include <bits/stdc++.h>
using namespace std;

void reverse(string s)
{
    stack<string> stk;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' and i < s.length())
        {
            word += s[i];
            i++;
        }
        stk.push(word);
    }
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}

int main()
{
    string s = "How are you?";
    reverse(s);
}