/**
 *    author:  tourist
 *    created: 08.04.2024 10:39:13
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = int(1e6) + 10;

int cnt_a[N];
int cnt_b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b(m);
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        for (int x : b)
        {
            cnt_b[x] += 1;
        }
        int cur = 0;
        for (int i = 0; i < m; i++)
        {
            if (cnt_a[a[i]] < cnt_b[a[i]])
            {
                cur += 1;
            }
            cnt_a[a[i]] += 1;
        }
        int ans = (cur >= k);
        for (int i = m; i < n; i++)
        {
            if (cnt_a[a[i - m]] <= cnt_b[a[i - m]])
            {
                cur -= 1;
            }
            cnt_a[a[i - m]] -= 1;
            if (cnt_a[a[i]] < cnt_b[a[i]])
            {
                cur += 1;
            }
            cnt_a[a[i]] += 1;
            ans += (cur >= k);
        }
        cout << ans << '\n';
        for (int x : b)
        {
            cnt_b[x] -= 1;
        }
        for (int i = 0; i < m; i++)
        {
            cnt_a[a[n - 1 - i]] -= 1;
        }
    }
    return 0;
}
