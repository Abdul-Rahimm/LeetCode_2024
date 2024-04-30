// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int MFS(vector<vector<int>> &A)
{
    int m = A.size();
    vector<vector<int>> t(m, vector<int>(m));

    // initialization
    for (int col = 0; col < m; col++)
    {
        t[0][col] = A[0][col];
    }

    for (int row = 1; row < m; row++)
    {
        for (int col = 0; col < m; col++)
        {
            t[row][col] = A[row][col] + min({t[row - 1][col],
                                             t[row - 1][max(0, col - 1)],
                                             t[row - 1][min(m - 1, col + 1)]});
        }
    }

    return *min_element(t[m - 1].begin(), t[m - 1].end());
}
int minFallingPathSum(vector<vector<int>> &A)
{
    return MFS(A);
}