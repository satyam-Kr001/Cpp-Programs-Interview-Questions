//If only one number is missing from Array......................................
#include <bits/stdc++.h>
using namespace std;

int oneNumMissing(int arr[], int N, int n)
{
    int sum = 0;
    int NaturalSum = N * (N + 1) / 2;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "Missing number is " << NaturalSum - sum;
    return 1;
}
int main()
{
    int arr[] = {1, 2, 3, 5, 6};
    int N = 6;
    int n = sizeof(arr)/sizeof(int);
    oneNumMissing(arr, N, n);
}

