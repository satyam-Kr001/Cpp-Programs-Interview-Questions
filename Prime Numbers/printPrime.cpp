#include <bits/stdc++.h>
using namespace std;

void primeNumbers(int n)
{
    if (n <= 1)
    {
        cout << "Not Prime";
        return;
    }
    int i, j = 0;
    for (i = 2; i < n; i++)
    {
        for (j = 2; j < n; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (i == j)
            cout << i << " ";
    }
}

void isPrime(int n)
{
    int i = 0;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            break;
        }
    }
    if (i == n)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }
}
// Better Approach ..........................................

int isPrime2(int n)
{
    for (int i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void printPrime(int num){
    for(int i=2; i<num; i++){
        if(isPrime2(i)){
            cout << i << " ";
        }
    }
}



int main()
{
    int n = 45;
    // int num = fib(n);
    // cout << isPrime2(39);
    // primeNumbers(20);
    printPrime(20);
    // cout << num;
}