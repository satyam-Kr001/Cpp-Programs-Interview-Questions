#include <bits/stdc++.h>
using namespace std;
#define n 3

// const int n = 3;
void transpose(int arr[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        { //............Only traverse in upper traingle...............
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

void rotateBy90(int arr[][n])
{
    for (int i = 0; i < n; i++)
    // ..........................Traverse through each row...............
    {
        int l = 0;
        int r = n - 1;
        while (l < r)
        // .........................Reverse the first row............................
        {
            int temp = arr[i][l];
            arr[i][l] = arr[i][r];
            arr[i][r] = temp;

            l++;
            r--;
        }
    }
}

void display(int arr[][n])
{
    cout << "Matrix are : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // int n;
    // cout << "Enter the size of a matrix" << endl;
    // cin >> n;
    // int arr[n][n];
    // cout << "Enter a matrix element :" << endl;
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    display(arr);
    transpose(arr);
    display(arr);
    rotateBy90(arr);
    display(arr);

    return 0;
}