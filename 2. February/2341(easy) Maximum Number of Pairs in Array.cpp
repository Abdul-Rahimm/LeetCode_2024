// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<int> numberOfPairs(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int count = 0;

    // 11.222.33
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == nums[i + 1])
        {
            count++;
            i++;
        }
    }

    vector<int> ans(2);

    ans[0] = count;
    ans[1] = nums.size() - (count * 2);

    return ans;
}

int main()
{
    vi nums{1, 3, 2, 1, 3, 2, 2};
    vi ans = numberOfPairs(nums);

    for (int i : ans)
        cout << i << " ";
}