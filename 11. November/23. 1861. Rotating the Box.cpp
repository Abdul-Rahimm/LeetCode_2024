// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int n = box.size();
        int m = box[0].size();

        vector<vector<char>> ans(m, vector<char>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (box[i][j] == '#')
                {
                    // shift right
                    int copy = j;
                    while (j + 1 < m && box[i][j + 1] == '.')
                    {
                        box[i][j] = '.';
                        box[i][j + 1] = '#';
                        j++;
                    }

                    // bring back j to original pos
                    j = copy;
                }
            }
        }

        int ansCol = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < m; j++)
            {
                ans[j][ansCol] = box[i][j];
            }
            ansCol++;
        }

        return ans;
    }
};