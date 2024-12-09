// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int getLargestOutlier(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int total = accumulate(nums.begin(), nums.end(), 0);
    int result = INT_MIN;

    for (int curr : nums)
    {

        int outlier = total - 2 * curr;
        int sum = (total - curr) / 2;

        if (mp.count(outlier))
        {
            result = max(result, outlier);
        }

        if (2 * sum + curr == total && mp.count(sum))
        {
            result = max(result, curr);
        }

        mp[curr]++;
    }

    return result;
}

int main()
{
    vi nums{2, 3, 5, 10};
    cout << getLargestOutlier(nums) << endl;
}