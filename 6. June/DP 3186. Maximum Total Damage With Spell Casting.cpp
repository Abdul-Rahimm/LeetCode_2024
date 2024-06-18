// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int dp[100001];
long long solve(vector<int> &power, int n, int i, unordered_set<int> &st)
{
    if (i >= n)
        return 0;
    // if (dp[i] != -1)
    //     return dp[i];

    unordered_set new_st = st;

    int take = 0;
    if (st.find(power[i]) == st.end())
    {
        for (int idx = -2; idx <= 2; idx++)
        {
            if (idx != 0)
                new_st.insert(power[i] + idx);
        }

        take = power[i] + solve(power, n, i + 1, new_st);
    }

    int not_take = solve(power, n, i + 1, st);

    return dp[i] = max(take, not_take);
}

long long maximumTotalDamage(vector<int> &power)
{
    int n = power.size();
    unordered_set<int> st;
    memset(dp, -1, sizeof(dp));

    return solve(power, n, 0, st);
}

int main()
{
    vi power{1, 1, 3, 4};
    vi power2{7, 1, 6, 6};
    long long ans = maximumTotalDamage(power2);
    cout << ans << endl;
}