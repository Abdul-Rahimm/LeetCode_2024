// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string makeFancyString(string s)
{
    string ans = "";
    ans.push_back(s[0]);
    int n = s.size(), cnt = 1;

    for (int i = 1; i < n; i++)
    {
        if (s[i] == ans.back())
        {
            cnt++;
            if (cnt < 3)
                ans.push_back(s[i]);
        }
        else
        {
            cnt = 1;
            ans.push_back(s[i]);
        }
    }

    return ans;
}