#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main()
{
    int n, sum = 0, flag = 0;

    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (sum == 0 || s.find(sum) != s.end())
        {
            cout << "Subarray with sum = 0 exists :)";
            flag = 1;
            break;
        }

        s.insert(sum);
    }
    if (flag == 0)
    {
        cout << "Subarray with sum = 0 does not exist :(";
    }
}