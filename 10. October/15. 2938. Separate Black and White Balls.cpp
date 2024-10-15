// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long minimumSteps(string s)
{
    int j = s.size() - 1;
    long long ans = 0;

    for (int i = j; i >= 0; i--)
    {
        if (s[i] == '0')
            continue;

        ans += j - i;
        j--;
    }

    return ans;
}