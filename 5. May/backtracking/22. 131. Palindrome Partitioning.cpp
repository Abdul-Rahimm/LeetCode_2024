// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    int n;

    bool isPalindrome(string &s, int l, int r)
    {

        while (l < r)
        {

            if (s[l] != s[r])

                return false;

            l++;

            r--;
        }

        return true;
    }

    void backtrack(string &s, int idx, vector<string> curr, vector<vector<string>> &result)
    {

        if (idx == n)
        {

            result.push_back(curr);

            return;
        }

        for (int i = idx; i < n; i++)
        {

            if (isPalindrome(s, idx, i))
            {

                curr.push_back(s.substr(idx, i - idx + 1));

                backtrack(s, i + 1, curr, result);

                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {

        n = s.length();

        vector<vector<string>> result;

        vector<string> curr;

        backtrack(s, 0, curr, result);

        return result;
    }
};