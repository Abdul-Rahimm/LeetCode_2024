// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
// #include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void print1d(vi nums)
{
    for (int i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}
void print(vii ans)
{
    for (vi row : ans)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}

struct VectorHash
{
    size_t operator()(const vector<int> &v) const
    {
        size_t seed = v.size();
        for (int i : v)
        {
            seed ^= i + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};
struct VectorEqual
{
    bool operator()(const vector<int> &v1, const vector<int> &v2) const
    {
        return v1 == v2;
    }
};

unordered_set<vector<int>, VectorHash, VectorEqual> st;

void solve(vector<int> &can, int target, vector<vector<int>> &ans, vector<int> &current, int i)
{

    if (target == 0)
    {
        sort(current.begin(), current.end());

        if (st.find(current) == st.end())
        {
            ans.push_back(current);
            st.insert(current);
        }
        return;
    }

    if (i >= can.size() || target < 0)
        return;

    // take case
    current.push_back(can[i]);
    solve(can, target - can[i], ans, current, i + 1);

    // not take case
    current.pop_back();
    solve(can, target, ans, current, i + 1);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> current;

    solve(candidates, target, ans, current, 0);

    return ans;
}

int main()
{
    vector<int> nums{2, 5, 2, 1, 2};
    int target = 5;

    vii ans = combinationSum2(nums, target);
    print(ans);
}