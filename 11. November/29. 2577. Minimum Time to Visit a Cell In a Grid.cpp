// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

typedef vector<int> vi;
vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int minimumTime(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;

    if (grid[0][1] > 1 && grid[1][0] > 1)
        return -1;

    priority_queue<vi, vector<vi>, greater<vi>> pq;
    pq.push({0, 0, 0});

    int time = 0;
    while (!pq.empty())
    {
        int nodes = pq.size();
        int score = INT_MAX;
        while (nodes--)
        {
            vi curr = pq.top();
            pq.pop();

            score = min(score, curr[0]);
            int i = curr[1], j = curr[2];

            grid[i][j] = -1; // mark visited

            if (i == n - 1 && j == m - 1)
                return time;

            for (vector<int> dir : directions)
            {
                int nx = i + dir[0];
                int ny = j + dir[1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == -1)
                    continue;

                pq.push({grid[nx][ny], nx, ny});
            }
        }

        if (time + 1 < score)
            while (time + 1 <= score)
                time += 2;
        else
            time++;
    }

    return time;
}

int main()
{

    vii grid{{0, 1, 3, 2}, {5, 1, 2, 5}, {4, 3, 8, 6}};
    int ans = minimumTime(grid);
    cout << ans << endl;
}