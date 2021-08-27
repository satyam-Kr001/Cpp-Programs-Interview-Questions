#include <bits/stdc++.h>
using namespace std;

void numDivByaAndbandBoth(int num, int a, int b)
{
    int c1 = num / a;
    int c2 = num / b;
    int c3 = num / (a * b);

    int res = (c1 + c2) - c3;
    cout << res;
}

// ............When two number is subtracted gcd of that number doesnot chnages............................//

void euclid_GCD(int a, int b)
{
    while (b != 0)
    {
        int rem = a%b;
        a=b;
        b=rem;
    }
    cout << "GCD = " << a;
}

int main()
{
    int a, b, n;
    // cin >> n;
    // cin >> a >> b;
    // numDivByaAndbandBoth(n, a, b);
    euclid_GCD(42, 24);
}