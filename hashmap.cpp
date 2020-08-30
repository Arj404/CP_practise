#include <iostream>
#include <map>
using namespace std;

bool findcommon(int array1[], int array2[], int n1, int n2)
{
    map<char, bool> map1;
    for (int i = 0; i < n1; i++)
    {
        map1.insert(make_pair(array1[i], true));
    }
    for (int i = 0; i < n2; i++)
    {
        if (map1.find(array2[i]) != map1.end())
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int array1[] = {'a', 'd', 'f', 't', 'h', 'g'};
    int array2[] = {'x', 's', 'f', 'r', 'q'};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    cout << findcommon(array1, array2, n1, n2) << endl;
    return 0;
}