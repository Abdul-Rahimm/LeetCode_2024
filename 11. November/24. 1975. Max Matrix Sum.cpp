// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    typedef long long ll;
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum = 0;
        long long smallest = 1e9;
        int n = matrix.size();

        int negatives = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] < 0)
                {
                    negatives++;
                }
                sum += abs(matrix[i][j]);
                smallest = min(smallest, abs(ll(matrix[i][j])));
            }
        }

        if (negatives % 2 == 1)
            return sum - 2 * smallest;

        return sum;
    }
};
