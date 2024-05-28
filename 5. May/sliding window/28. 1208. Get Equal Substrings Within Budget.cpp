// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();
    // vector<int> differences(n + 1, 0);
    int len = 0;
    int sum = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        int diff = abs(int(s[j]) - int(t[j]));
        // differences[j] = diff;
        sum += diff;

        while (sum > maxCost)
        {
            sum -= abs(s[i] - t[i]);
            i++;
        }

        len = max(len, j - i + 1);
        j++;
    }
    return len;
}

int main()
{
    string s = "abcd";
    string t = "cdef";
    int maxcost = 3;

    cout << equalSubstring(s, t, maxcost);
}