// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> mp; // O(m*n)

        for (auto &row : matrix)
        { // O(m)
            string rowKaNature = "";

            int firstVal = row[0];
            for (int col = 0; col < n; col++)
            { // O(n)
                rowKaNature += (row[col] == firstVal) ? "S" : "B";
            }

            mp[rowKaNature]++;
        }

        int maxRows = 0;
        for (auto &it : mp)
        {
            maxRows = max(maxRows, it.second);
        }

        return maxRows;
    }
};
