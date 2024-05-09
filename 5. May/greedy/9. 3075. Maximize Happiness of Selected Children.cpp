class Solution
{
public:
    long long maximumHappinessSum(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());

        int rank = 0;
        long long total = 0;
        for (int i = 0; i < k; i++)
        {

            total += max(nums[i] - rank, 0);
            rank++;
        }

        return total;
    }
};