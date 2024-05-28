// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();
    vector<int> differences(n + 1, 0);
    int len = 0;
    int sum = 0;

    for (int i = 0, j = 0; i < n && j < n; i++)
    {

        int diff = abs(int(s[i]) - int(t[i]));
        differences[i] = diff;
        sum += diff;

        if (sum <= maxCost)
        {
            j++;
            len = max(len, j);
        }
        else
        {
            sum -= differences[i];
            i++;
        }
    }
    return len;
}