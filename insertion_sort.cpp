#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void intertion(int a[], int n)
{
    int k;
    for (int i = 1; i < n; i++)
    {
        k = a[i];
        int j = i - 1;
        for (; j >= 0 && a[j] > k; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = k;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    intertion(a, n);
    cout << "Sorted : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " : ";
    }
    cout << endl;
    return 0;
}