// Perfect Numbers are those Numbers whose sum of all the divisors are equal to that number

#include <bits/stdc++.h>
using namespace std;

// Check whether the number is perfect or not.........................

int perfectNum(int num)
{
    int sum = 0;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum == num)
        return 1;
    else
        return 0;
}

/* Calculating the maximum sum of 0 1 modified array as that 0 1 array will give the subarray which
    has maximum number of 1's that means that subarray has the maximum perfect number;
*/

void maxsum(int arr[], int k, int n)
{
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum = sum + arr[i];
    }
    int maxsum = sum;

    for (int i = k; i < n; i++)
    {
        sum -= arr[i-k];
        sum += arr[i];
        maxsum = max(sum,maxsum);
    }
    cout << maxsum;
}

void perfectSum(int arr[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (perfectNum(arr[i]))
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }
    maxsum(arr, k, n);
}

int main()
{
    int arr[] = {28,2,3,6,496,99,8128,24};
    int k = 4;
    int n = 8;
    perfectSum(arr, n, k);
    // cout << perfectNum(n);
}
