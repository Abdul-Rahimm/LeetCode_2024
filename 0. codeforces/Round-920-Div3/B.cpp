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

    string a, b;
    cin >> a >> b;

    int first = 0;
    int second = 0;
    for (int i = 0, j = 0; i < n; i++, j++)
    {
        if (a[i] == '1' && b[j] == '0')
            first++;
        else if (a[i] == '0' && b[j] == '1')
            second++;
    }

    cout << max(first, second) << endl;
}