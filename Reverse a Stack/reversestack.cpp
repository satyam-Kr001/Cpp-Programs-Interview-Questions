#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int> &stk) // Using extra space............................................
{
    stack<int> temp;
    while (!stk.empty())
    {
        temp.push(stk.top());
        stk.pop();
    }
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
}

// -----------------------------Uisng recursion Without any extra Space-------------------------------------//

void insertAtBottom(stack<int> &stk, int ele)
{
    if (stk.empty())
    {
        stk.push(ele);
        return;
    }
    int topele = stk.top();
    stk.pop();
    insertAtBottom(stk, ele);

    stk.push(topele);
}

void reverseRecursively(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    int ele = stk.top();
    stk.pop();
    reverseRecursively(stk);
    insertAtBottom(stk, ele);
}

void display(stack<int> stk)
{
    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.push(6);
    stk.push(7);
    stk.push(8);
    display(stk);
    reverseRecursively(stk);
    display(stk);
}
