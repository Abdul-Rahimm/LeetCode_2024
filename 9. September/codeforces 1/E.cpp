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
    int n; // len
    int k; // start
    cin >> n >> k;
    // 3 4 5 6 7
    vector<int> forward(1, k); // first element as k
    vector<int> backward;

    for (int i = k + 1, index = 1; i < n + k; i++, index++)
    {
        forward.push_back(forward[index - 1] + i);
    }

    int sum = 0;
    for (int i = n + k - 1; i >= k; i--)
    {
        sum += i;
        backward.push_back(sum);
    }

    print(forward);
    reverse(forward.begin(), forward.end());
    print(forward);
}