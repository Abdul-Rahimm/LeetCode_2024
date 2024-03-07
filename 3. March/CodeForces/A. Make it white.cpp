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
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
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

    int i = 0, j = s.size() - 1;

    while (i < s.size())
    {
        if (s[i] == 'B')
            break;
        i++;
    }

    while (j >= 0)
    {
        if (s[j] == 'B')
            break;
        j--;
    }

    cout << j - i + 1 << endl;
}