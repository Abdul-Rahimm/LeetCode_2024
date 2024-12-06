// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {

        int i = 0;
        int j = 0;
        int ans = 0;

        int n = str1.size();
        int m = str2.size();

        while (i < n && j < m)
        {
            char c1 = str1[i];
            char c2 = str2[j];

            if (c1 == c2 || char(c1 + 1) == c2 || (c1 == 'z' && c2 == 'a'))
            {
                j++;
            }

            i++;
        }

        cout << str1.size() << " " << str2.size() << endl;
        return j == m;
    }
};