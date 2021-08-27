#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int k = 3;
    int minDiff = INT_MAX;
    for (int i = 0; i <= n - k; i++)
    {
        int diff = 0;
        for (int j = k + i; j <= i; j--)
        {
            diff -= arr[j];
            cout << diff << " ";
            if (diff < minDiff)
            {
                minDiff = diff;
            }
        }
        cout << minDiff << " ";
    }
}
