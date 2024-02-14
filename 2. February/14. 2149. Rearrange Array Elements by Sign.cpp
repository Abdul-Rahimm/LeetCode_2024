vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> ans;
    int n = nums.size();

    queue<int> pos, neg;

    for (int i : nums)
    {
        if (i > 0)
            pos.push(i);
        else
            neg.push(i);
    }

    for (int i = 0; i < n / 2; i++)
    {
        ans.push_back(pos.front());
        pos.pop();
        ans.push_back(neg.front());
        neg.pop();
    }

    return ans;
}