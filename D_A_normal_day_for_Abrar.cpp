// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
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
    int n, l, r;
    cin >> n >> l >> r;
    vi nums(n);
    for (int &i : nums)
        cin >> i;

    int i = 0, j = 0;
    int ans = 0, sum = 0;

    while (j < n)
    {
        sum += nums[j];

        if (sum >= l && sum <= r)
        {
            // behtereen condition
            ans++;
            sum = 0;
            i = j + 1;
        }

        if (sum > r)
        {
            while (sum > r && i < j)
            {
                sum -= nums[i];
                i++;

                if (sum >= l && sum <= r)
                {
                    ans++;
                    sum = 0;
                    i = j + 1;
                }
            }
        }

        j++;
    }

    cout << ans << endl;
}