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
    // cin >> tc;

    while (tc--)
        solve();

    return 0;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int i = 0, j = 0;
    string ans;
    bool status = true;
    while (status == true)
    {
        status = false;
        i = 0, j = 0;
        while (j < n)
        {
            if (s[j] != s[j + 1])
            {
                for (int x = i; x <= j; x++)
                    ans.push_back(s[i]);
                j++;
                i = j;
                continue;
            }

            if (s[j] == s[j + 1])
            {
                j++;
            }

            if (j - i + 1 == k)
            {
                j++;
                i = j;
                status = true;
            }
            n = ans.size();
        }
    }

    cout << ans << endl;
}