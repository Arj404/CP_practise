#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class dist
{
public:
    int r;
    int c;
    int d;
    dist(int x, int y, int z)
    {
        this->r = x;
        this->c = y;
        this->d = z;
    }
};

int mindist(vector<vector<int>> grid)
{
    dist source(0, 0, 0);
    int N, M;
    N = grid.size();
    M = grid[0].size();
    bool visited[N][M];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (grid[i][j] == '0')
                visited[i][j] = true;
            else
                visited[i][j] = false;
            if (grid[i][j] == 's')
            {
                source.r = i;
                source.c = j;
            }
        }
    }
    queue<dist> q;
    q.push(source);
    visited[source.r][source.c] = true;
    while (!q.empty())
    {
        dist p = q.front();
        q.pop();

        if (grid[p.r][p.c] == 'd')
            return p.d;

        if (p.r - 1 >= 0 && visited[p.r - 1][p.c] == false)
        {
            q.push(dist(p.r - 1, p.c, p.d + 1));
            visited[p.r - 1][p.c] = true;
        }
        if (p.r + 1 < N && visited[p.r + 1][p.c] == false)
        {
            q.push(dist(p.r + 1, p.c, p.d + 1));
            visited[p.r + 1][p.c] = true;
        }
        if (p.c - 1 >= 0 && visited[p.r][p.c - 1] == false)
        {
            q.push(dist(p.r, p.c - 1, p.d + 1));
            visited[p.r][p.c - 1] = true;
        }
        if (p.c + 1 < M && visited[p.r][p.c + 1] == false)
        {
            q.push(dist(p.r, p.c + 1, p.d + 1));
            visited[p.r][p.c + 1] = true;
        }
    }
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int result;
    result = mindist(grid);
    cout << result << endl;
    return 0;
}