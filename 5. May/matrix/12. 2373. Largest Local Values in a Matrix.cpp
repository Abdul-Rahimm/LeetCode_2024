class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int rows = grid.size();

        vector<vector<int>> ret(rows - 2, vector<int>(rows - 2, 0));

        for (int i = 1; i < rows - 1; i++)
        {
            for (int j = 1; j < rows - 1; j++)
            {

                // currently standing at [1][1]
                int largest = grid[i - 1][j - 1];
                largest = max(largest, grid[i - 1][j]);
                largest = max(largest, grid[i - 1][j + 1]);

                largest = max(largest, grid[i][j - 1]);
                largest = max(largest, grid[i][j]);
                largest = max(largest, grid[i][j + 1]);

                largest = max(largest, grid[i + 1][j - 1]);
                largest = max(largest, grid[i + 1][j]);
                largest = max(largest, grid[i + 1][j + 1]);

                ret[i - 1][j - 1] = largest;
            }
        }

        return ret;
    }
};