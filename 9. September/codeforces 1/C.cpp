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

int64_t ceil_div(int64_t a, int64_t b)
{
    return a / b + ((a ^ b) > 0 && a % b != 0);
}

void solve()
{
    int64_t x, y, k;
    cin >> x >> y >> k;

    x = ceil_div(x, k);
    y = ceil_div(y, k);

    cout << max(2 * x - 1, 2 * y) << endl;
}