// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
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

void solve();

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;

    while (tc--)
        solve();

    return 0;
}

void solve()
{
    vector<vector<int>> nums;

    for (int i = 0; i < 4; i++)
    {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b});
    }

    sort(nums.begin(), nums.end());

    cout << abs(nums[3][0] - nums[0][0]) * abs(nums[3][1] - nums[0][1]) << endl;
}