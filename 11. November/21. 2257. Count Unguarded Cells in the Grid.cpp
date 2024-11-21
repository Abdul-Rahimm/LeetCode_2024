// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int N, M;
vector<vector<int>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// bool inRange(int i, int j) { return i >= 0 && i < N && j >= 0 && j < M; }

void DFS(vector<vector<char>> &vis, int x, int y)
{

    // up
    for (int i = x - 1; i >= 0; i--)
    {
        if (vis[i][y] == 'W')
            break;

        if (vis[i][y] != 'g')
            vis[i][y] = 'm';
    }

    // down
    for (int i = x + 1; i < N; i++)
    {
        if (vis[i][y] == 'W')
            break;

        if (vis[i][y] != 'g')
            vis[i][y] = 'm';
    }

    // right
    for (int i = y + 1; i < M; i++)
    {
        if (vis[x][i] == 'W')
            break;

        if (vis[x][i] != 'g')
            vis[x][i] = 'm';
    }

    // left
    for (int i = y - 1; i >= 0; i--)
    {
        if (vis[x][i] == 'W')
            break;

        if (vis[x][i] != 'g')
            vis[x][i] = 'm';
    }
}

int countUnguarded(int n, int m, vector<vector<int>> &guards,
                   vector<vector<int>> &walls)
{

    vector<vector<char>> vis(n, vector<char>(m, '.'));
    N = n;
    M = m;

    for (vector<int> row : guards)
    {
        int x = row[0];
        int y = row[1];
        vis[x][y] = 'g';
    }
    for (vector<int> row : walls)
    {
        int x = row[0];
        int y = row[1];
        vis[x][y] = 'W';
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (vis[i][j] == 'g')
                DFS(vis, i, j);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (vis[i][j] == '.')
                ans++;
        }
    }

    // print(vis);

    return ans;
}

int main()
{
    int n = 6;
    int m = 10;
    vii guards{{0, 6}, {2, 2}, {2, 5}, {1, 2}, {4, 9}, {2, 9}, {5, 6}, {4, 6}};
    vii walls{{1, 5}};

    int ans = countUnguarded(n, m, guards, walls);

    cout << ans << endl;
}