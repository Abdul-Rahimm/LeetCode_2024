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
    // cin >> tc;

    while (tc--)
        solve();

    return 0;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    int maxNum = max(a, b);

    if (maxNum == 1)
    {
        cout << "1/1";
    }
    else if (maxNum == 2)
    {
        cout << "5/6";
    }
    else if (maxNum == 3)
    {
        cout << "2/3";
    }
    else if (maxNum == 4)
    {
        cout << "1/2";
    }
    else if (maxNum == 5)
    {
        cout << "1/3";
    }
    else if (maxNum == 6)
    {
        cout << "1/6";
    }
}