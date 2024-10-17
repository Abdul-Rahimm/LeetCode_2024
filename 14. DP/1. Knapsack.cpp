// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
using namespace std::chrono;

vector<int> wt{
    1,
    3,
    4,
    5,
    1,
    3,
    4,
    5,
    1,
    3,
    4,
    5,
    1,
    3,
    4,
    5,
};
vector<int> val{
    1,
    4,
    5,
    10,
    1,
    3,
    4,
    5,
    1,
    3,
    4,
    5,
    1,
    3,
    4,
    5,
};
int n = wt.size() + 1;
int m = val.size() + 1;
int dp[20][20];

int solve(int i, int w)
{
    if (i >= wt.size())
        return 0;
    // if (dp[i][w] != -1)
    //     return dp[i][w];

    int take = 0;
    if (w - wt[i] >= 0)
        take = val[i] + solve(i + 1, w - wt[i]);

    int nottake = solve(i + 1, w);

    return max(take, nottake);
}

int main()
{
    int cap = 7;
    memset(dp, -1, sizeof(dp));

    // Start measuring time
    auto start = high_resolution_clock::now();

    int ans = solve(0, cap);
    cout << "Maximum value: " << ans << endl;

    // Stop measuring time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
}
