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
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            char ch;
            cin >> ch;

            if (ch == '#')
                ans.push_back(j + 1);
        }
    }

    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << " ";

    cout << endl;
}