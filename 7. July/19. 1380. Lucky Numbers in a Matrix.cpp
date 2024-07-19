// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void FillRowsWithMinimum(int n, int m, vector<vector<int>> &matrix, vector<int> &row_minimums)
{
    for (int i = 0; i < n; i++)
    {
        int row_minimum = matrix[i][0];
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] < row_minimum)
                row_minimum = matrix[i][j];
        }

        row_minimums[i] = row_minimum;
    }
}
void FillColumnsWithMax_Compare(int n, int m, vector<vi> &matrix, vi &col_maximums)
{
    for (int i = 0; i < n; i++)
    {
        int col_maximum = INT_MIN;
        for (int j = 0; j < m; j++)
        {
            if (matrix[j][i] > col_maximum)
                col_maximum = matrix[j][i];
        }

        col_maximums[i] = col_maximum;
    }
}
void compare(vi &vec1, vi &vec2, vi &result)
{
    for (int i = 0; i < vec1.size(); i++)
    {
        for (int j = 0; j < vec2.size(); j++)
        {
            if (vec1[i] == vec2[j])
                result.push_back(vec1[i]);
        }
    }
}
vector<int> luckyNumbers(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> result;

    vector<int> row_minimums(n);
    vector<int> col_maximums(m);

    FillRowsWithMinimum(n, m, matrix, row_minimums);
    FillColumnsWithMax_Compare(n, m, matrix, col_maximums);

    compare(row_minimums, col_maximums, result);

    return result;
}

int main()
{
    vector<vi> matrix{{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    vector<int> ans = luckyNumbers(matrix);
    print(ans);
}