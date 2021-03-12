#include <iostream>
using namespace std;

void solution(int a[], int n)
{
    int i, count = 0;
    int pre[n];
    pre[0] = a[0];
    for (i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    for (i = 0; i < n; i++)
    {
        if (pre[i] == 0)
            count++;
    }
    cout << count;
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        
    }

    solution(a, n);
}