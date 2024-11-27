// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    typedef pair<int, int> pii;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;

    int BFS(vector<vector<int>> &grid, queue<pii> q)
    {

        int level = 0;

        while (!q.empty())
        {
            int nodes = q.size();

            while (nodes--)
            {

                pii top = q.front();
                int x = top.first;
                int y = top.second;
                q.pop();

                for (vector<int> dir : directions)
                {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if (nx >= 0 & nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }

        return max(level - 1, 0);
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        queue<pii> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    // ans += BFS(i, j, grid);
                    q.push({i, j});
                }
            }
        }

        int ans = BFS(grid, q);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return ans;
    }
};
