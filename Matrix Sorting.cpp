#include <bits/stdc++.h>
using namespace std;
#define MAX 10
void sortMat_RowWise(int a[MAX][MAX], int n)
{
    //Sort each row of the matrix
    for (int i = 0; i < n; i++)
    {
        sort(a[i], a[i] + n);
    }

    //Transpose the obtained matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int t = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = t;
        }
    }
}

void printMat(int a[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    int a[MAX][MAX];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    sortMat_RowWise(a, n);
    printMat(a, n);
}