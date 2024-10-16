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
#define int long long
void solve();
const int M = 1e9 + 7;

int powm(int x, int n)
{
    x %= M;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    int p = powm(x * x, n / 2);
    if (n % 2)
        return p * x % M;
    else
        return p;
}

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;

    while (tc--)
        solve();

    return 0;
}
void solve()
{
    int t;
    cin >> t;

    vector<int> n(t);
    for (int i = 0; i < t; i++)
        cin >> n[i];

    vector<int> k(t);
    for (int i = 0; i < t; i++)
        cin >> k[i];

    for (int i = 0; i < t; i++)
    {
        cout << powm(2, k[i]) << endl;
    }
}