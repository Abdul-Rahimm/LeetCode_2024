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
    int n, k;
    cin >> n >> k;

    int num;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mp[num]++;
    }

    int l = -1, st = -1, cnt = 0, mx = 0;

    for (auto row : mp)
    {
        if (l != row.first - 1)
        {
            st = row.first;
            cnt = row.second;
        }
        else
        {
            if (row.first - st + 1 > k)
            {
                cnt -= mp[row.first - k];
            }
            cnt += row.second;
        }

        l = row.first;
        mx = max(mx, cnt);
    }

    cout << mx << endl;
}