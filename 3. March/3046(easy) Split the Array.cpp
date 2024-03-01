class Solution
{
public:
    bool isPossibleToSplit(vector<int> &nums)
    {
        int n = nums.size();
        int ones = 0;

        vector<int> freq(101, 0);

        for (int i : nums)
            freq[i]++;

        for (int i : freq)
        {
            if (i == 1)
                ones++;
            if (i > 2)
                return false;
        }

        if (ones % 2 == 1)
            return false;

        return true;
    }
};