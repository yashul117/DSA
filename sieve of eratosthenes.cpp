#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool primes[n + 1];
    memset(primes, true, sizeof(primes));

    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == true)
        {
            for (int p = i * i; p <= n; p += i)
            {
                primes[p] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        cout << i << " " << primes[i] << "\n";
    }
}