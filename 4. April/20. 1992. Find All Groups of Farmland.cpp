// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int rows, cols;

vector<int> DFS(int i, int j, vector<vector<int>> &land)
{

    // already pushed the top right co ordinates
    vector<int> row{i, j};

    // now come down and then go right max
    while (i + 1 < rows && land[i + 1][j] == 1)
    {
        i++;
    }
    while (j + 1 < cols && land[i][j + 1] == 1)
    {
        j++;
    }

    // mark the land some other number as to not visit again
    for (int x = row[0]; x <= i; x++)
    {
        for (int y = row[1]; y <= j; y++)
        {
            land[x][y] = 100;
        }
    }

    row.push_back(i);
    row.push_back(j);

    return row;
}

vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    vector<vector<int>> ans;

    rows = land.size();
    cols = land[0].size();

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if (land[i][j] == 1)
            {
                vector<int> pos = DFS(i, j, land);
                ans.push_back(pos);
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> land{
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1},
    };

    vector<vector<int>> ans = findFarmland(land);

    for (vector<int> row : ans)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}