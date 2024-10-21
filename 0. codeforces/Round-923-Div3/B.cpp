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
    cin >> tc;

    while (tc--)
        solve();

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int &i : nums)
        cin >> i;

    unordered_map<char, int> mp;
    for (int i = 25; i >= 0; i--)
    {
        mp[char(i + 'a')] = 0;
    }

    string s;
    for (int i = 0; i < n; i++)
    {
        int curr = nums[i];

        for (auto &row : mp)
        {
            if (row.second == curr)
            {
                s.push_back(row.first);
                row.second++;
                break;
            }
        }
    }

    cout << s << endl;
}