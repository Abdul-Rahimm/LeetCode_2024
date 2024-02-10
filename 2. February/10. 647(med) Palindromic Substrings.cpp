#include <bits/stdc++.h>
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define endl "\n"
using namespace std;

int xcheckPalindrome(string s)
{
    int last = s.size() - 1;
    int first = 0;

    while (first < last)
    {
        if (s[first] != s[last])
            return 0;

        first++;
        last--;
    }

    return 1;
}
int xcountSubstrings(string sen)
{
    int n = sen.size();
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        string s;
        int count = 1;
        for (int j = i; j < n; j++)
        {
            s = sen.substr(i, count);
            // cout << s << endl;
            count++;
            ans += xcheckPalindrome(s);
        }
    }

    return ans;
}

int main()
{
    fastio;
    cout << xcountSubstrings("aaa") << endl;

    // string s = "abcde";
    // string x = s.substr(0, 3);
    // cout << x << " " << s << endl;

    return 0;
}