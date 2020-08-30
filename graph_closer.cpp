#include <iostream>
#include <vector>
using namespace std;

void addvertex(vector<int> v[], int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

int transitive(vector<int> v[], int n){
    
}

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v[n];
    int x, y;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        addvertex(v, x, y);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " - ";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " : ";
        }
        cout << endl;
    }
    return 0;
}