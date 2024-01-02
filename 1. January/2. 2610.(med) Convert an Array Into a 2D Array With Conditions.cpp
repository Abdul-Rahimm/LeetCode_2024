// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

unordered_map<int, int> mp;
vector<vector<int>> ans;

vector<vector<int>> findMatrix(vector<int> &nums)
{
    int n = nums.size();

    for (int i : nums)
    {
        mp[i]++;
    }

    int count = 0;
    while (count != n)
    {
        vector<int> row;

        for (auto &pair : mp)
        {
            if (pair.second > 0)
            {
                row.push_back(pair.first);
                pair.second--;
                count++;
            }
        }

        ans.push_back(row);
    }

    return ans;
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

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    vii ans = findMatrix(nums);
    print(ans);
}