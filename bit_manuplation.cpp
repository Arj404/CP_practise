#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    n = 23;
    int x = 1;
    bool y;
    for (int i = 0; i < 8; i++)
    {
        y = n & x;
        cout << y << ":";
        //n = n >> 1;
        x = x*2;
    }
    n = n ^ 129;
    x=1;
    cout<<endl;
    for (int i = 0; i < 8; i++)
    {
        y = n & x;
        cout << y << ":";
        //n = n >> 1;
        x = x*2;
    }
    cout << endl;
    return 0;
}