// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
// #define for(n) for (int i = 0; i < n; i++)
// #define rev(n) for (int i = n; i >= 0; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define p1 cout << "-1\n";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vii;
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

    vi nums(n);
    for (int &i : nums)
    {
        cin >> i;
    }
    int mx = *max_element(all(nums));
    int mn = *min_element(all(nums));

    int extra = n > 1 ? 1 : 0;
    cout << (mx - mn) * (n - extra) << endl;
}