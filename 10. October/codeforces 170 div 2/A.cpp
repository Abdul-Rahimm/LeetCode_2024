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
    string s, t;
    cin >> s >> t;

    int len = min(s.size(), t.size());
    int cnt = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] != t[i])
            break;

        cnt++;
    }

    int extraCopy = 0;
    if (cnt != 0)
        extraCopy++;

    cout << (s.size() - cnt) + (t.size() - cnt) + cnt + extraCopy << endl;
}