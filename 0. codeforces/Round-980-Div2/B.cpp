// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
// #define for(n) for(int i = 0; i < n ; i++)
// #define rev(n) for(int i = n; i >= 0 ; i--)
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define p1 cout << "-1\n";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vii;
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
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;

    sort(nums.begin(), nums.end());
    if (nums[0] == k)
    {
        cout << *min_element(all(nums)) << endl;
        return;
    }

    int mn = INT_MAX;
    int count = 0;
    int nextcount = 0;
    ll total = 0;
    ll ans = 0;
    int iterations = 0;

    while (ans < k)
    {
        for (int i = count; i < n; i++)
        {
            if (nums[i] <= mn)
            {
                mn = nums[i];
                count++; // number of minimums
            }
            else
                break;
        }

        int add = (mn) * (nums.size() - nextcount);

        total += min(k, add);
        if (k < ans)
            total += min(k, count);

        ans += min(k, add);

        nextcount = count;
        iterations++;
    }

    cout << total << endl;
}