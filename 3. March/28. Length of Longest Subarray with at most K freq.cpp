int maxSubarrayLength(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;

    int i = 0;
    int j = 0;
    int n = nums.size();
    int ans = 0;

    while (j < n)
    {

        if (mp[nums[j]] < k)
        {
            // increase the window size to allow more elements to come in
            mp[nums[j]]++;
            j++;
        }
        else
        {
            while (nums[i] != nums[j])
                i++;

            mp[nums[j]]--;
            i++;
        }

        ans = max(ans, j - i);
    }

    return ans;
}