#include <iostream>
#include <vector>
#include <queue>
#include<stack>
using namespace std;

void addEdge(vector<int> v[], int x, int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}

void bfs(vector<int> v[],int n)
{
    bool visit[n];
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    queue<int> q;
    q.push(0);
    visit[0] = true;
    int pt;
    while (!q.empty())
    {
        pt = q.front();
        cout<<pt<<"-> ";
        q.pop();
        for (int i = 0; i < v[pt].size(); i++)
        {
            if (!visit[v[pt][i]])
            {
                q.push(v[pt][i]);
                
                visit[v[pt][i]] = true;
            }
        }
    }
    cout<<endl;
}

// dfs using stack
void dfstack(vector<int> v[], int n){
    bool visit[n];
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    stack<int> s;
    s.push(0);
    visit[0] = true;
    int pt;
    while (!s.empty())
    {
        pt = s.top();
        cout<<pt<<"-> ";
        s.pop();
        for (int i = v[pt].size()-1; i >=0; i--)
        {
            if (!visit[v[pt][i]])
            {
                s.push(v[pt][i]);
                
                visit[v[pt][i]] = true;
            }
        }
    }
    cout<<endl;
}

// dfs using recursion
void dfshelper(vector<int> v[],int a,bool visit[]){
    cout<<a<<"-> ";
    visit[a] = true;
    for(int i=0;i<v[a].size();i++){
        if(!visit[v[a][i]]){
            dfshelper(v,v[a][i],visit);
        }
    }
}

void dfsrecursion(vector<int> v[],int n){
    bool visit[n];
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    dfshelper(v, 0,visit);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v[n];
    int t, x, y;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> y;
        addEdge(v, x, y);
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
    bfs(v,n);
    dfstack(v,n);
    dfsrecursion(v,n);
    return 0;
}