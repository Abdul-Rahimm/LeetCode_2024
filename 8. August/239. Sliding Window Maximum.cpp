// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<vi> vii;

typedef vector<int> vi;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{

    int n = nums.size();

    int i = 0;
    int j = 0;
    set<int> st;
    vector<int> ans;
    unordered_map<int, int> mp;

    while (j < n)
    {
        if (j - i >= k)
        {
            if (mp[nums[i]] == 1)
                st.erase(nums[i]);

            mp[nums[i]]--;
            i++;
        }

        st.insert(nums[j]);
        mp[nums[j]]++;

        if (j >= k - 1)
        {
            int number = *st.rbegin();
            ans.push_back(number);
        }

        j++;
    }

    return ans;
}

int main()
{

    vi nums{1, 3, -1, -3, 5, 3, 6, 7};
    vi ans = maxSlidingWindow(nums, 3);
}