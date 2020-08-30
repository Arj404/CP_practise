#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int gcd(int i, int j)
{
    if (i == j)
        return i;

    if (i > j)
        return gcd(i - j, j);
    return gcd(i, j - i);
}

bool check(int m, int n)
{
    int a;
    a = gcd(m, n);
    if (a == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << check(a, b)<<endl;
    }
    return 0;
}
