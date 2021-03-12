#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

void EEA(int a, int b, int &x, int &y)
{
    if (a == 1)
    {
        x = 1;
        y = 0;
        return;
    }

    int X1, Y1;
    EEA(b % a, a, X1, Y1);

    x = Y1 - (b / a) * X1;
    y = X1;
}

int modInverse(int a, int m)
{
    if (a == 0 || gcd(a, m) != 1)
        return -1;

    int x, y;
    EEA(a, m, x, y);
    return abs(x);
}

int find_min_x(int rem[], int pp[], int inv[], int n, int prod)
{
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x += rem[i] * pp[i] * inv[i];
    }
    x = x % prod;

    return x;
}

int main()
{
    int n, prod, i;
    cin >> n;
    int num[n], rem[n], pp[n], inv[n];
    prod = 1;
    for (i = 0; i < n; i++)
    {
        cin >> num[i];
        prod *= num[i];
    }

    for (i = 0; i < n; i++)
    {
        cin >> rem[i];
    }

    for (i = 0; i < n; i++)
    {
        pp[i] = prod / num[i];
        inv[i] = modInverse(pp[i], num[i]);
    }
    cout << find_min_x(rem, pp, inv, n, prod) << "\n";
}