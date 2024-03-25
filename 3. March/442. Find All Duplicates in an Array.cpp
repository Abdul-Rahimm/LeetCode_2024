class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        int n = nums.size();

        for (int i = 0; i < n; i++)
        {

            int num = abs(nums[i]) - 1; // the raw value
            int index = nums[num];

            if (index < 0)
            {
                ans.push_back(abs(nums[i]));
                continue;
            }

            nums[num] *= -1;
        }

        return ans;
    }
};