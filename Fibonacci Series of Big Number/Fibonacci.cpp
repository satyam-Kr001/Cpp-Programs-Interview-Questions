#include <bits/stdc++.h>
using namespace std;

int fibMemo(int n, int dp[])
{
    if (n == 0 or n == 1)
        return n;

    if (dp[n] != 0)
        return dp[n];

    int fibn1 = fibMemo(n - 1, dp);
    int fibn2 = fibMemo(n - 2, dp);
    int fibn = fibn1 + fibn2;
    dp[n] = fibn;

    return fibn;
}

int main()
{
    int n = 45;
    int dp[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = 0;
    } 
    int res = fibMemo(n, dp);
    cout << res;
}