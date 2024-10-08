// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
// #include "../../utils.h"
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef array<int, 2> ii;
typedef vector<ii> vii;
const int mod = 1e9 + 7;

void solve(int iteration, int tests);

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;

    for (int i = 0; i < tc; i++)
        solve(i + 1, tc);

    return 0;
}

void solve(int iteration, int tests)
{
    int n, curr;
    cin >> n;
    vector<int> nums(n);
    vector<int> diff(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i == 0)
            diff[i] = nums[i];
        else
        {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    int maxNum = 0;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (diff[i] > maxNum)
        {
            count = diff[i];
            maxNum = diff[i];
        }
        else if (diff[i] == maxNum)
        {
            count++;
            maxNum = count;
        }
    }

    if (iteration < tests)
        cout << "Case " << iteration << ": " << count << endl;
    else
        cout << "Case " << iteration << ": " << count;
}