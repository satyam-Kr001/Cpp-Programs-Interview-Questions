#include <bits/stdc++.h>
using namespace std;

// int subarraysum(int arr[], int k, int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             if (sum == k)
//             {
//                 cout << i << " " << j - 1 << endl;
//                 return 1;
//             }
//             // if (sum > sum || j == n)
//             //     break;
//             sum = sum + arr[j];
//         }
//     }
//     return 0;
// }
int subarraySum(int arr[], int k, int n)
{
    int low = 0;
    int high = 0;
    int sum = arr[0];
    while (low < n and high < n)
    {
        if (sum == k)
        {
            cout << low + 1 << " " << high + 1;
            return 1;
        }
        else if (sum < k)
        {
            high++;
            sum += arr[high];
        }

        else if (sum > k)
        {
            sum -= arr[low];
            low++;
        }
    }
    return -1;
}

int main()
{
    int n = 4;
    int arr[] = {1, 2, 3, 8};
    int k = 5;
    subarraySum(arr, k, n);
}
