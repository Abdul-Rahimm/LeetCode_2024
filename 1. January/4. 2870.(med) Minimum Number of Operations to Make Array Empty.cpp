// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minOperations(vector<int> &nums)
{
    unordered_map<int, int> mp;

    for (int i : nums)
        mp[i]++;

    int ans = 0;

    for (auto &pair : mp)
    {
        int count = pair.second;

        if (count == 1)
            return -1;

        ans += ceil(float(count) / 3);
    }

    return ans;
}

int main()
{
    vi nums{2, 3, 3, 2, 2, 4, 2, 3, 4};
    cout << minOperations(nums) << endl;
}