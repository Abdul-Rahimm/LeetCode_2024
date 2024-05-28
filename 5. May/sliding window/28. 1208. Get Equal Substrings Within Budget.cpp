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
    int i = 0, j = 0, idx = -1;

    while (i < n && j < n)
    {
        idx++;
        int diff = abs(int(s[idx]) - int(t[idx]));
        differences[i] = diff;
        sum += diff;

        if (sum <= maxCost)
        {
            len = max(len, j - i + 1);
            j++;
        }
        else
        {
            sum -= differences[i];
            i++;
        }
    }
    return len;
}

int main()
{
    string s = "abcd";
    string t = "acde";
    int maxcost = 0;

    cout << equalSubstring(s, t, maxcost);
}