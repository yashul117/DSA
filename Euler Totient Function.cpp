//Program to find Euler Totient function of all the integers from 1 to n

#include <iostream>
using namespace std;

void phi_1_to_n(int n)
{
    int phi[n + 1];
    phi[0] = 0;
    phi[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        phi[i] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (phi[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                phi[j] = phi[j] - phi[j] / i;
            }
        }
    }
}

// Solution by Divisor Sum Property
/*
void phi_1_to_n(int n)
{
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
            phi[j] -= phi[i];
}
*/
int main()
{
    int n;
    cin >> n;
    phi_1_to_n(n);
}