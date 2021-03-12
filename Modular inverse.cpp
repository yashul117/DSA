#include <bits/stdc++.h>
using namespace std;

int EEA(int a, int b, int &x, int &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int X1, Y1;
    int gcd = EEA(b % a, a, X1, Y1);

    x = Y1 - (b / a) * X1;
    y = X1;
    

    return gcd;
}

int modInv(int a, int m)
{
    int x, y;
    int g = EEA(a, m, x, y);
    if (g != 1 || a == 0)
        return -1;

    return x;
}

int main()
{
    int a, m;
    cin >> a >> m;
    cout << modInv(a, m);
}