// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int scoreOfString(string s)
{
    int n = s.size();
    int result = 0;

    for (int i = 0; i < n - 1; i++)
    {
        result += abs(s[i] - s[i + 1]);
    }

    return result;
}
