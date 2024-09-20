// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isPalindrome(string s)
{
    int n = s.length();
    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

string shortestPalindrome(string s)
{
    int n = s.length();
    int i = n - 1;
    string ans = "";

    if (isPalindrome(s))
        return s;

    while (i >= 1)
    {
        string current = s.substr(i, n);
        reverse(current.begin(), current.end());

        string newtest = current + s;
        if (isPalindrome(newtest))
            return newtest;
        i--;
    }

    return ans;
}