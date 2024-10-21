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

    string s;
    cin >> s;
    int first = -1;
    int last = -1;
    for (int i = 0, j = n - 1; i < n; i++, j--)
    {
        if (first == -1 && s[i] == 'B')
            first = i;
        if (last == -1 && s[j] == 'B')
            last = j;

        if (first != -1 && last != -1)
            break;
    }

    cout << last - first + 1 << endl;
}