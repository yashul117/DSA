#include <bits/stdc++.h>
using namespace std;
/*
void Sieve(int low, int high)
{
    int limit = floor(sqrt(high));
    bool isPrime[limit + 1];
    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> Primes;
    Primes.push_back(2);

    for (int i = 3; i <= limit; i += 2)
    {
        if (isPrime[i])
            Primes.push_back(i);
    }

    bool res[high - low + 1];
    memset(res, true, sizeof(res));

    for (int i = 0; Primes[i] * Primes[i] <= high; i++)
    {
        int base = (low / Primes[i]) * Primes[i];
        if (base < low)
            base += Primes[i];

        for (int j = base; j <= high; j += Primes[i])
        {
            res[j - low] = false;
        }
        if (base == Primes[i])
            res[i - low] = true;
    }

    vector<int> PrimeSieve;
    for (int i = low; i <= high; i++)
    {
        if (res[i - low])
            PrimeSieve.push_back(res[i - low]);
    }
    for (int i = low; i <= high; i++)
    {
        cout << PrimeSieve.at(i - low) << " ";
    }
}

int main()
{
    int low, high;
    cin >> low >> high;
    Sieve(low, high);
}
*/

#define MAX 100001

vector<int> *sieve()
{
    bool isPrime[MAX];
    for (int i = 0; i < MAX; i++)
    {
        isPrime[i] = true;
    }

    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int> *Primes = new vector<int>();
    Primes->push_back(2);

    for (int i = 3; i < MAX; i++)
    {
        if (isPrime[i])
            Primes->push_back(i);
    }
    return Primes;
}

void printPrimes(int l, int r, vector<int> *&Primes)
{
    bool isPrime[r - l + 1];
    for (int i = 0; i <= r - l; i++)
        isPrime[i] = true;

    for (int i = 0; Primes->at(i) * (long long)Primes->at(i) <= r; i++)
    {
        int currPrime = Primes->at(i);
        long long base = (l / currPrime) * currPrime;

        if (base < l)
            base += currPrime;

        for (long long j = base; j <= r; j += currPrime)
        {
            isPrime[j - l] = false;
        }
        if (base == currPrime)
            isPrime[base - l] = true;
    }

    for (int i = 0; i <= r - l; i++)
    {
        if (isPrime[i])
            cout << i + l << " ";
    }
}

int main()
{
    vector<int> *Primes = sieve();
    int t; 
    cin >> t;

    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        printPrimes(l, r, Primes);
    }
}