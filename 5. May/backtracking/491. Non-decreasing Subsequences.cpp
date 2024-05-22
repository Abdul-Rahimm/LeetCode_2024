// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
void print(vii &ans)
{
    for (vector<int> row : ans)
    {
        for (int i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}
struct hashFunction
{
    size_t operator()(const vector<int> &myVector) const
    {
        std::hash<int> hasher;
        size_t answer = 0;
        for (int i : myVector)
        {
            answer ^= hasher(i) + 0x9e3779b9 +
                      (answer << 6) + (answer >> 2);
        }
        return answer;
    }
};
bool nonDecreasing(vi &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] > nums[i + 1])
            return false;
    }
    return true;
}
unordered_set<vi, hashFunction> st;

void solve(vi &nums, int i, vi &curr, vii &ans)
{
    if (i >= nums.size())
    {
        if (curr.size() >= 2 && nonDecreasing(curr) && st.find(curr) == st.end())
        {
            ans.push_back(curr);
            st.insert(curr);
        }
        return;
    }

    curr.push_back(nums[i]);
    solve(nums, i + 1, curr, ans);
    curr.pop_back();
    solve(nums, i + 1, curr, ans);
}
vector<vector<int>> findSubsequences(vector<int> &nums)
{
    vi curr;
    vii ans;
    solve(nums, 0, curr, ans);

    return ans;
}

int main()
{
    vector<int> nums{4, 6, 7, 7};
    vii ans = findSubsequences(nums);

    print(ans);
}