class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        int highest = 0;
        int count = 0;

        for (int i : nums)
        {
            mp[i]++;
            highest = max(highest, mp[i]);
        }

        for (auto pair : mp)
        {
            int number = pair.first;
            int freq = pair.second;

            if (freq == highest)
                count++;
        }

        return count * highest;
    }
};