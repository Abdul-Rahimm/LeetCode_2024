// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int n;
vector<int> days, costs;
int solve(int i, int covered)
{

    while (i < n && days[i] < covered)
        i++;

    if (i >= n)
        return 0;

    int day = costs[0] + solve(i + 1, i);

    int week = costs[1] + solve(i + 1, i + 6);

    int month = costs[2] + solve(i + 1, i + 29);

    return min({day, week, month});
}

int mincostTickets(vector<int> &a, vector<int> &b)
{
    n = a.size();
    days = a;
    costs = b;

    return solve(0, 1);
}

int main()
{
    vector<int> days{1, 4, 6, 7, 8, 20};
    vector<int> costs{2, 7, 15};

    int ans = mincostTickets(days, costs);
    cout << ans << endl;
}