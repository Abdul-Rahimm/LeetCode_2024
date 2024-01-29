// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vii directions{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// goal is n-1, m-1
int n, m;

void printMaze(vii nums)
{
    for (vector<int> row : nums)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;
}

bool solve(vii nums, vector<vector<bool>> &vis, int i, int j)
{
    // visiting the node so mark it true
    vis[i][j] = true;
    cout << "Visiting (" << i << " , " << j << ") Node" << endl;

    if (i == n - 1 && j == m - 1)
    {
        cout << "WE HAVE REACHED THE GOAL STATE" << endl;
        return true; // goal state reached
    }
    // not the goal state. so explore
    for (vector<int> dir : directions)
    {
        int newX = i + dir[0];
        int newY = j + dir[1];

        // if already visited dont go back there
        if ((newX < 0 || newX >= n || newY < 0 || newY >= m) || nums[newX][newY] == 0 || vis[newX][newY] == true)
            continue;

        if (solve(nums, vis, newX, newY))
            return true;
    }

    // exiting the node
    vis[i][j] = false;

    cout << "Returning from (" << i << " , " << j << ") Node" << endl;
    return false;
}

int main()
{
    vector<vector<int>> nums{
        {1, 0, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 0, 0, 1}};

    n = nums.size();
    m = nums[0].size();

    vector<vector<bool>> visited(nums.size(), vector<bool>(nums[0].size(), false));

    // printMaze(nums);
    cout << solve(nums, visited, 0, 0) << endl;
}