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
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for (int &i : nums)
    {
        cin >> i;
    }

    priority_queue<int> pq(nums.begin(), nums.end());

    int turns = 0;
    while (!pq.empty())
    {
        vector<int> temp(x, 0);
        for (int i = 0; i < x; i++)
        {
            if (!pq.empty())
            {
                temp[i] = pq.top();
                pq.pop();
                temp[i]--;
            }
        }

        for (int i = 0; i < x; i++)
        {
            if (temp[i] > 0)
            {
                pq.push(temp[i]);
            }
        }

        turns++;
    }

    cout << turns << endl;
}