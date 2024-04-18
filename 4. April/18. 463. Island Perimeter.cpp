class Solution
{
public:
    int rows, cols;

    int addScore(int i, int j, vector<vector<int>> &grid)
    {
        int score = 0;

        // check every side one by one
        if (i - 1 < 0 || grid[i - 1][j] == 0)
            score++;
        if (i + 1 >= rows || grid[i + 1][j] == 0)
            score++;

        if (j - 1 < 0 || grid[i][j - 1] == 0)
            score++;
        if (j + 1 >= cols || grid[i][j + 1] == 0)
            score++;

        return score;
    }

    int islandPerimeter(vector<vector<int>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        int score = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {

                if (grid[i][j] == 0)
                    continue;

                score += addScore(i, j, grid);
            }
        }

        return score;
    }
};