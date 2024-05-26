// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int mod = 1e9 + 7;
unordered_map<string, int> mp;

bool isOkay(string s)
{
    int absent = 0;
    int late = 0;

    for (char i : s)
    {
        if (i == 'L')
            late++;
        else if (i == 'A')
        {
            late = 0;
            absent++;
        }
        else
        {
            late = 0;
        }

        if (late >= 3)
            return false;
    }

    if (absent > 1)
        return false;

    return true;
}

int solve(int n, string curr)
{
    if (n <= 0)
    {
        if (isOkay(curr))
            return 1;

        return 0;
    }

    string key = to_string(n) + curr;

    if (mp.count(key))
        return mp[key];

    // absent case
    int absent = (solve(n - 1, curr + "A")) % mod;

    // late case
    int late = (solve(n - 1, curr + "L")) % mod;

    // present
    int present = (solve(n - 1, curr + "P")) % mod;

    int num = (absent + late) % mod;
    num = (num + present) % mod;

    return mp[key] = num;
}

int checkRecord(int n)
{
    return solve(n, "");
}
