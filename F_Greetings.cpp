// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define pb push_back
#define all(x) x.begin(), x.end()
#define int long long
#define py cout << "YES\n";
#define pn cout << "NO\n";
#define forn(a, b) for (int i = a; i < b; i++)
#define nl cout << endl;
#define pii pair<int, int>
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mod = 1e9 + 7;

void solve(int i);

signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    cin >> tc;

    for (int i = 1; i <= tc; i++)
        solve(i);

    return 0;
}

void solve(int tc)
{
    // function<int(int, int)> solve = [&](int i, int j) -> int

    int n;
    cin >> n;
    vii nums;
    forn(0, n)
    {
        int a, b;
        cin >> a >> b;
        nums.push_back({a, b});
    }

    sort(all(nums));
    // for (auto row : nums)
    // {
    //     for (int i : row)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    vii rank;

    for (int i = 0; i < n; i++)
    {
        rank.push_back({i, nums[i][1]});
    }

    // nl;
    // for (auto row : rank)
    // {
    //     for (int i : row)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    sort(all(rank), [](vi a, vi b)
         { return a[1] <= b[1]; });

    // int mn = rank[0][0];
    indexed_set st;
    st.insert(rank[0][0]);

    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        // if (rank[i][0] <= mn)
        // {
        //     ans += i;
        //     mn = rank[i][0];
        // }
        int temp = 0;
        temp = st.size() - st.order_of_key(rank[i][0]);

        ans += temp;
        st.insert(rank[i][0]);
    }

    cout << ans << endl;
}