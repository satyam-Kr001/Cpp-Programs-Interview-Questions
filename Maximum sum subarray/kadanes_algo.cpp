#include <bits/stdc++.h>
using namespace std;

int kadanesAlgo(int arr[], int n)
{
    int maxsum = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        if (currsum > maxsum)
            maxsum = currsum;
        else if (currsum < maxsum)
        {
            currsum = 0;
        }
    }
    return maxsum;
}
int main()
{
    int arr[] = {-1, 4, 3, -2, 7};
    int n = 5;
    int res = kadanesAlgo(arr, n);
    cout << res;
}