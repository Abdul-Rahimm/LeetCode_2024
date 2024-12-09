// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
{
    vector<int> change{1};
    int n = nums.size();
    vector<bool> ans;

    string parity = nums[0] % 2 == 0 ? "even" : "odd";

    for (int i = 1; i < n; i++)
    {

        if ((parity == "even" && nums[i] % 2 == 1) || (parity == "odd" && nums[i] % 2 == 0))
        {
            parity = parity == "odd" ? "even" : "odd";
            change.push_back(change.back() + 1);
        }
        else
        {
            change.push_back(change.back());
        }
    }

    for (vector<int> row : queries)
    {
        int start = row[0];
        int end = row[1];

        int diff = change[end] - change[start];
        cout << "diff: " << diff << " | " << end << " " << start << endl;

        if (diff == end - start)
            ans.push_back(true);
        else
            ans.push_back(false);
    }

    return ans;
}