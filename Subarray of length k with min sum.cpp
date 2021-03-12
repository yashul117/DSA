#include <iostream>
using namespace std;

void solution(int a[], int n, int k)
{
    int i, res, sum;

    res = sum = 0;

    for (i = 0; i < k; i++)
    {
        res += a[i];
    }
    sum = res;
    for (i = k; i < n; i++)
    {
        sum += a[i] - a[i - k];
        res = min(sum, res);
    }

    cout << res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    solution(a, n, k);
}