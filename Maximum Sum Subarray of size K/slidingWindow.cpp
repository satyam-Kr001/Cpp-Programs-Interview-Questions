#include <bits/stdc++.h>
using namespace std;

void slidingWindowMaximumSumSubarrayOfSizeK(int arr[], int N, int K, int X)
{
    int sum = 0, ans = 0;
    for (int i = 0; i < K; i++)
    {
        sum += arr[i];
    }
    if (sum < X)
    {
        ans = sum;
    }

    for (int i = 0, j = K; j < N; j++)
    {
        sum -= arr[i];
        sum += arr[j];
        i++;

        if (sum < X)
        {
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
int main()
{
    int arr[] = {7, 5, 4, 6, 8, 9};
    int N = 6;
    int K = 3;
    int X = 18;
    slidingWindowMaximumSumSubarrayOfSizeK(arr, N, K, X);
}