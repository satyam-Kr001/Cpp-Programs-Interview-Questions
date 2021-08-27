//  This is KMP(Knuth Morris Prat algorithm)..............works with two string is rotation of each other or not..4

#include <bits/stdc++.h>
using namespace std;

void checkRotation(string s1, string s2)
{
    string temp = s1 + s1;
    if (s1.length() != s2.length())
    {
        cout << "Nope" << endl;
    }
    else
    {
        if (temp.find(s2) != string::npos)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "N0";
        }
    }
}

void rotation(string s1, string s2)
{
    queue<char> q1;
    queue<char> q2;
    for (int i = 0; i < s1.length(); i++)
    {
        q1.push(s1[i]);
    }
    for (int j = 0; j < s2.length(); j++)
    {
        q2.push(s2[j]);
    }
    int k = s2.length();
    while (k--)
    {
        char ch = q2.front();
        q2.pop();
        q2.push(ch);
        if (q1 == q2)
        {
            cout << "Is rotation";
            return;
        }
    }
    cout << "Not a rotation";
}
int main()
{
    string s1 = "abcdef";
    string s2 = "efabcd";
    // checkRotation(s1, s2);
    rotation(s1,s2);
}