// The idea behind this problem is to find elements which repeats more than N/2 times in array.
// Brute force approach. two for loop.
// Sort array then find no of elements.

#include <bits/stdc++.h>
using namespace std;

void morreaAlgo(int arr[], int n)
{
    // sort(arr,arr+n);
    // int count = 1;
    // for (int i = 1; i < n; i++)
    // {
    //     if (arr[i] == arr[i - 1])
    //     {
    //         count++;
    //     }
    //     if (count > n / 2)
    //         cout << count;
    //     // else
    //     // {
    //     //     count = 1;
    //     // }
    // }
    int mjrele = arr[0]; // majority element let first element is major ele.....
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == mjrele)
        {
            count++; // if encounter same as mjrele then incre,emt the counter.
        }
        else
            count--; // if encounter different variable then decrement the counter....
        if (count == 0) // if count is zero then change the majority ele.
        {
            mjrele = arr[i]; 
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++) // again check is majority element is really a major element with given condition
    {
        if (arr[i] == mjrele)
            count++;
    }
    if (count > n / 2)
    {
        cout << mjrele;
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    int arr[] = {1, 2, 2, 3, 2};
    int n = 5;
    morreaAlgo(arr, n);
}