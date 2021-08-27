#include <bits/stdc++.h>
using namespace std;

void change(int arr[], int n, int cash)
{
    int denom = 0;
    for (int i = 0; i < n; i++)
    {
        denom = int(cash / arr[i]);
        cout << arr[i] << "->" << denom << endl;
        cash = cash % arr[i];
    }
}

int main()
{
    int arr[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    change(arr, 10, 676);
}