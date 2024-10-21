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
    long long n, f, a, b;
    cin >> n >> f >> a >> b;

    vector<long long> nums(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        f -= min((nums[i + 1] - nums[i]) * a, b);

        if (f <= 0 && i < n)
        {
            cout << "NO" << endl;
            return;
        }
    }

    if (f >= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}