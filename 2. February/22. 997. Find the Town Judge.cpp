class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> nums(n + 1);

        for (vector<int> row : trust)
        {
            int a = row[0];
            int b = row[1];

            nums[a]++;
            nums[b]--;
        }

        for (int i = 1; i <= n; i++)
        {
            if (nums[i] == (-1 * n) + 1)
                return i;
        }

        return -1;
    }
};