#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int sum, max;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sum = 0;
    max = a[0];
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if(sum>max)
        {
            max = sum;
        }
        if(sum<0)
        {
            sum = 0;
        }
    }
    cout << max;
}