#include <bits/stdc++.h>
using namespace std;


void anagram(string s1, string s2)
{
    int flag = 1;
    unordered_map<char, int> m1;
    for (auto i : s1)
    {
        m1[i]++;
    }
    for (auto j : s2)
    {
        m1[j]--;
    }
    for (auto i : m1)
    {
        if (i.second != 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        cout << "Anagram";
    else
        cout << "Not Angram";
}
int main()
{
    string s1 = "silent";
    string s2 = "sil";
    anagram(s1, s2);
}