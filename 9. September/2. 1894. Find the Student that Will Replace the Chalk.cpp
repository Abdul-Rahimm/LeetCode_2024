// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int chalkReplacer(vector<int> &chalk, int k)
{
    long long total = 0;
    for (int i : chalk)
        total += i;

    int n = chalk.size();
    long long remaining = k % total;

    for (int i = 0; i < n; i++)
    {
        if (remaining < chalk[i])
            return i;

        remaining -= chalk[i];
    }

    return 0;
}