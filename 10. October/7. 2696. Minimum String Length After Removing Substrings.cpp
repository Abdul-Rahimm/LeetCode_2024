// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int minLength(string s)
{
    int r = 1, w = 1;
    int n = s.size();

    while (r < n)
    {
        s[w] = s[r];

        if (w > 0 && ((s[w] == 'B' && s[w - 1] == 'A') || (s[w] == 'D' && s[w - 1] == 'C')))
        {
            w--;
        }
        else
            w++;

        r++;
    }

    return w;
}

int main()
{
    string s = "ABFCACDB";
    cout << minLength(s) << endl;
    return 0;
}