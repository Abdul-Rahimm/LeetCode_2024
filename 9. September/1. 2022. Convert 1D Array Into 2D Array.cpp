// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<vector<int>> construct2DArray(vector<int> &nums, int rows, int cols)
{

    int n = nums.size();

    if (n != rows * cols)
        return {};

    vector<vector<int>> ans(rows, vector<int>(cols));
    int index = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            ans[i][j] = nums[index];
            index++;
        }
    }

    return ans;
}