// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n;
int m;
vector<vector<int>> directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool checkValidRegion(vector<vector<int>> &points, vector<vector<int>> &grid1)
{

    for (auto point : points)
    {
        int x = point[0];
        int y = point[1];

        if (grid1[x][y] == 0)
            return false;
    }

    return true;
}

void DFS(int i, int j, vector<vector<int>> &grid2, vector<vector<int>> &points)
{

    if (i < 0 || i >= n || j < 0 || j >= m || grid2[i][j] == 0)
        return;

    // already explored
    grid2[i][j] = 0;
    points.push_back({i, j});

    for (vector<int> dir : directions)
    {
        int new_x = dir[0];
        int new_y = dir[1];

        DFS(i + new_x, j + new_y, grid2, points);
    }

    return;
}

int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
{

    n = grid1.size();
    m = grid1[0].size();
    int regions = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (grid2[i][j] == 1)
            {
                // coordinates has every single point which has a 1 on grid2 for a particular island
                vector<vector<int>> coordinates;
                DFS(i, j, grid2, coordinates);

                // this function will compare the Island coordinates of grid2
                //  and see if theyre all present in grid1
                if (checkValidRegion(coordinates, grid1))
                    regions++;
            }
        }
    }

    return regions;
}

int main()
{
    vii grid1{{1, 1, 1, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 0, 1, 1}};
    vii grid2{{1, 1, 1, 0, 0}, {0, 0, 1, 1, 1}, {0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 0}};
    int regions = countSubIslands(grid1, grid2);
    // cout << regions << endl;
}