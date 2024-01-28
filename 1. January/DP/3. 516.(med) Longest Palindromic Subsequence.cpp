// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string s;
int n;

int checkPalindrome(string sen)
{
    int first = 0, last = sen.size() - 1;

    while (first < last)
    {
        if (sen[first] != sen[last])
            return 0;

        first++;
        last--;
    }

    return sen.size();
}

int solve(int i, string sen)
{

    if (i >= n)
        return 0;

    char a = s[i];
    string taken = sen + to_string(a);

    int take = checkPalindrome(sen) + solve(i + 1, taken);
    int ntake = solve(i + 1, sen);

    return max(take, ntake);
}

int longestPalindromeSubseq(string t)
{

    s = t;
    n = s.size();
    string s = "";

    return solve(0, s);
}

int main()
{
    cout << longestPalindromeSubseq("cbbd") << endl;
}