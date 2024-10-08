// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../../utils.h"
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
    // cin >> tc;

    while (tc--)
        solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;
    int ans = 0;

    vector<vector<int>> points;

    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        points.push_back({x, y});
    }

    sort(all(points));

    for (int i = 0; i < n - 1; i++)
    {
        // str line condition
        int currentX = points[i][0];
        int nextX = points[i + 1][0];

        if (currentX == nextX)
        {
            ans += n - 2;
        }
    }

    for (int i = 1; i < n - 2; i++)
    {

        int currentX = points[i][0];
    }

    cout << ans << endl;
}
