#include <bits/stdc++.h>
using namespace std;

long maxSubArraySum(long a[], int size)
{
    long max_so_far = a[0];
    long curr_max = a[0];

    for (int i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        long a[n],b[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        long max_sum = maxSubArraySum(a, n);

        cout << max_sum <<endl;
    }
    return 0;
}