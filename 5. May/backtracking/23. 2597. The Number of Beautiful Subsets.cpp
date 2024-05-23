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

int main()
{
    vi nums{2, 4, 6};
    int ans = beautifulSubsets(nums, 2);
}