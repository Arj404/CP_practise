#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int power(string s)
{
    int n, p, r;
    n = s.length();
    p = 1;
    r = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'C')
        {
            p = p * 2;
        }
        else
        {
            r = r + p;
        }
    }
    return r;
}

bool impossible(string s, int d)
{
    int n, r;
    n = s.length();
    r = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'S')
        {
            r++;
        }
    }
    if (r > d)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string switchs(string s)
{
    int n, l;
    n = s.length();
    l = n;
    bool flag;
    flag = 1;
    while (flag)
    {
        if (s[n] == 'C')
        {
            if (n + 1 < l && s[n + 1] == 'S')
            {
                s[n] = 'S';
                s[n + 1] = 'C';
                flag = 0;
            }
            else
            {
                n--;
            }
        }
        else
        {
            n--;
        }
        if (n < 0)
        {
            flag = 0;
        }
    }
    return s;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout<<"Case #"<<i+1<<": ";
        int d;
        string s;
        cin >> d >> s;
        int pw;
        pw = power(s);
        bool flag = 1;
        bool p = 1;
        if (impossible(s, d))
        {
            cout << "IMPOSSIBLE" << endl;
            flag = 0;
            p = 0;
        }
        int hack = 0;
        while (flag)
        {
            ++hack;
            s = switchs(s);
            pw = power(s);
            if (pw <= d)
            {
                flag = 0;
            }
        }
        if (p)
        {
            cout << hack << endl;
        }
    }
    return 0;
}