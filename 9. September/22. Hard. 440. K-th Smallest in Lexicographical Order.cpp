// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void solve(vector<int> &ans, int n, int k, int curr)
{
    if (curr > n)
        return;
    if (ans.size() == k)
        return;

    ans.push_back(curr);

    for (int i = 0; i <= 9; i++)
    {
        int nextNumber = (curr * 10) + i;

        if (nextNumber <= n)
            solve(ans, n, k, nextNumber);
        else
            break;
    }
}

int findKthNumber(int n, int k)
{
    vector<int> nums;

    for (int i = 1; i <= 9; i++)
        solve(nums, n, k, i);

    return nums[k - 1];
}

int main()
{
}