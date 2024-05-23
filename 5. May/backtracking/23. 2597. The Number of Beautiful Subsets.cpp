// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
vii allSubsets;
void print(vii nums)
{
    for (auto row : nums)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isBeautiful(vi &nums, int k)
{
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int diff = abs(nums[i] - nums[j]);

            if (diff == k)
                return false;
        }
    }

    return true;
}
void makeSubsets(vi &nums, int i, int k, vi &curr)
{
    if (i >= nums.size())
    {
        if (!curr.empty() && isBeautiful(curr, k))
            allSubsets.push_back(curr);
        return;
    }

    curr.push_back(nums[i]);
    makeSubsets(nums, i + 1, k, curr);
    curr.pop_back();
    makeSubsets(nums, i + 1, k, curr);
}
int beautifulSubsets(vector<int> &nums, int k)
{
    vector<int> current;
    makeSubsets(nums, 0, k, current);
    return allSubsets.size();
}
// -----------------------------------------------------------------------------------------------------

int k;
int result;

void solve(int i, vector<int> &nums, unordered_map<int, int> &mp)
{

    if (i >= nums.size())
    {
        result++;
        return;
    }

    // not take
    solve(i + 1, nums, mp);

    // take - with check
    if (mp[nums[i] + k] == 0 && mp[nums[i] - k] == 0)
    {
        mp[nums[i]]++;          // do
        solve(i + 1, nums, mp); // explore
        mp[nums[i]]--;          // undo
    }
}

int beautifulSubsets(vector<int> &nums, int K)
{
    k = K;
    result = 0;

    unordered_map<int, int> mp;

    solve(0, nums, mp);

    return result - 1;
}