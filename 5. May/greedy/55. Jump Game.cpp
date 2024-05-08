class Solution
{
public:
    bool canJump(vector<int> &nums)
    {

        int n = nums.size();
        int maxVision = 0;

        for (int i = 0; i < n && i <= maxVision; i++)
        {

            int number = nums[i];

            maxVision = max(maxVision, i + number);

            if (maxVision >= n - 1)
                return true;
        }

        return false;
    }
};