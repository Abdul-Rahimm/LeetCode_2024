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
int req;

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
    int n, m, k;
    cin >> n >> m >> k;
    req = k;

    unordered_map<int, int> mp1;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (mp1[num] == 0)
            mp1[num]++;
    }

    unordered_map<int, int> mp2;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        if (mp2[num] == 0)
            mp2[num]++;
    }

    int x = 0, y = 0;
    for (int i = 1; i <= k; i++)
    {
        bool status = false;

        if (mp1[i] > 0)
        {
            x++;
            status = true;
        }

        if (mp2[i] > 0)
        {
            y++;
            status = true;
        }

        if (!status)
        {
            cout << "NO" << endl;
            return;
        }
    }

    if (x >= k / 2 && y >= k / 2)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}