// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    vector<vector<int>> ans(2);
    vector<int> nums(100001, 0);
    int top = 0;

    for (vector<int> row : matches)
    {
        int winner = row[0];
        int loser = row[1];

        nums[winner] = nums[winner] == 0 || nums[winner] == -1 ? -1 : nums[winner];
        nums[loser] = max(1, nums[loser] + 1);

        top = max(top, max(winner, loser)); // saves the highest number
    }

    for (int i = 0; i <= top; i++)
    {
        if (nums[i] == 0)
            continue;
        else if (nums[i] == -1)
            ans[0].push_back(i);
        else if (nums[i] == 1)
            ans[1].push_back(i);
    }

    return ans;
}