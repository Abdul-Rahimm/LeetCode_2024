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
    int n;
    cin >> n;

    vector<int> nums(n);
    vector<int> diff;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (i > 0 && nums[i] != nums[i - 1])
        {
            diff.push_back(i - 1);
        }
    }

    int q;
    cin >> q;

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;

        // store all those elements jinka next is different from them
        ll lowerBound = lower_bound(diff.begin(), diff.end(), l) - diff.begin();

        if (lowerBound < diff.size() && diff[lowerBound] < r)
        {
            cout << diff[lowerBound] + 1 << " " << diff[lowerBound] + 2 << endl;
        }
        else
        {
            cout << "-1 -1" << endl;
        }
    }
}