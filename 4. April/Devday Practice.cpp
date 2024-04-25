// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
int ans = 0;

int dp(int t, int a, int b, int current, int prev)
{
    int curr = current;

    if (current > t)
        return prev;
    if (current == t)
        return t;

    // she has three choices +5, 0.5, +6
    int lemon = 5 + dp(t, a, b, current + 5, current);
    int water = dp(t, a, b, current / 2, current);
    int orange = 6 + dp(t, a, b, current + 6, current);

    return max(orange, max(lemon, water));
}

void solve()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t = 8, a = 5, b = 6;
    int prev = 0;
    // cin >> t >> a >> b;

    int DP = dp(t, a, b, 0, prev);

    cout << DP;
}
int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}