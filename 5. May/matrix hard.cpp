// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<vector<int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isSafe(int i, int j, int n)
{
    return i < 0 || i >= n || j < 0 || j >= n;
}
void fillSafenessFactor(vector<vector<int>> &safeness, vector<vector<int>> &grid, int n)
{

    queue<vector<int>> q;
    // traverse and find the theif positions
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                vector<int> row = {i, j};
                q.push(row);
            }
        }
    }

    int level = 0;
    while (!q.empty())
    {
        int nodes = q.size();

        while (nodes--)
        {
            vector<int> current = q.front();
            q.pop();

            int i = current[0];
            int j = current[1];

            if (safeness[i][j] == 0)
                safeness[i][j] = level;

            // ooper neechay aaju baaju push into the queue
            for (vector<int> dir : directions)
            {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if (isSafe(new_i, new_j, n) && safeness[new_i][new_j] == 0)
                {
                    vector<int> row = {new_i, new_j};
                    q.push(row);
                }
            }
        }
        level++;
    }
}
void print(vector<vector<int>> safeness)
{
    for (vector<int> row : safeness)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int maximumSafenessFactor(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> safeness(n, vector<int>(n, 0));

    fillSafenessFactor(safeness, grid, n);
    print(safeness);

    return 0;
}

int main()
{
    vector<vector<int>> grid{{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}};
    maximumSafenessFactor(grid);

    return 0;
}