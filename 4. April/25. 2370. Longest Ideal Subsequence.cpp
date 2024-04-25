// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int solve(string curr, string s, int k, int i)
{
    if (i >= s.size())
        return 1;

    // currently standing at index i
    string add = curr + s[i];
    int take = 0;
    if (abs(s[i] - s[i + 1]) <= k)
        take = 1 + solve(add, s, k, i + 1);

    int ntake = solve(curr, s, k, i + 1);

    return max(take, ntake);
}

int longestIdealString(string s, int k)
{

    return solve("", s, k, 0);
}

int main()
{
}