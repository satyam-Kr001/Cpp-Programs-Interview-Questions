#include <bits/stdc++.h>
using namespace std;

bool compare(map<char, int> smap, map<char, int> pmap)
{
    map<char, int>::iterator itr1;
    map<char, int>::iterator itr2;
    for (itr1 = smap.begin(), itr2 = pmap.begin(); itr1 != smap.end(); ++itr1, ++itr2)
    {
        if (itr1->first != itr2->second and (itr1->second != itr2->second))
            return false;
    }
    return true;
}
void noOfAnagrams(string s, string pat)
{
    map<char, int> smap;
    map<char, int> pmap;
    for (int i = 0; i < pat.length(); i++)
    {
        pmap[pat[i]]++;
    }
    for (int i = 0; i < pat.length(); i++)
    {
        smap[s[i]]++;
    }

    // int i = 0;
    int j = pat.length();
    int count = 0;

    while (j < s.length())
    {
        if (compare(smap, pmap))
        {
            count++;
            cout << j - pat.length() << " ";
        }
        smap[s[j]]++;
        smap[s[j - pat.length()]]--;
        // i++;
        j++;
    }

    if (compare(smap, pmap))
    {
        count++;
        cout << j-pat.length();
    }
    cout <<endl<<  count << endl;
}

int main()
{
    string s = "eaylnlfdxf";
    string pat = "irc
    ";
    noOfAnagrams(s, pat);
}