#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[26];
    string s;
    cin >> s;
    for (int i = 0; i < 26; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < s.length(); i++)
    {
        a[s[i] - 97]++;
    }
    sort(a, a + 26, greater<int>());
    int c = 0;
    cout << endl;
    for (int i = 1; i < 26 && a[i] > 0; i++)
    {
        if (a[i - 1] == a[i])
        {
            a[i]--;
            c++;
        }
    }
    cout << c << endl;
    return 0;
}