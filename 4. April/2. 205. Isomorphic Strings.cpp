// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isIsomorphic(string s, string t)
{
    vector<int> a(26, 0);
    vector<int> b(26, 0);

    for (char i : s)
        a[i - 'a']++;
    for (char i : t)
        b[i - 'a']++;

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());

    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
            return false;

        if (a[i] == 0 && b[i] == 0)
            break;
    }

    return true;
}

int main()
{
    // cout << isIsomorphic("egg", "add") << endl;
    cout << isIsomorphic("foo", "bar") << endl;
    cout << isIsomorphic("paper", "title") << endl;
}