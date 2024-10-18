// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
// #include "../../utils.h"
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
    int n, r;
    cin >> n >> r;

    int ans = 0;
    vector<int> nums(n);

    for (int &i : nums)
    {
        cin >> i;

        ans += i / 2;

        i = i % 2;
    }
    ans *= 2;
    int filledRows = ans / 2;
    int remainingRows = r - filledRows;

    int remainingPeople = accumulate(nums.begin(), nums.end(), 0);

    ans += remainingPeople > remainingRows ? (remainingRows * 2) - remainingPeople : remainingPeople;

    cout << ans << endl;
}