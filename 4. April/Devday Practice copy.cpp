// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
int ans = 0;

void solve()
{
    int n, q, second = 0, third = 0, save = -1;
    string s;

    cin >> n;
    cin >> s;
    cin >> q;

    for (int j = 0; j < q; j++)
    {

        int t, x;
        char c;

        cin >> t >> x;
        cin >> c;

        if (t == 1)
        {
            s[x - 1] = c;
        }
        else if (t == 2)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] < 90)
                    s[i] += 32;
            }
        }
        else if (t == 3)
        {
            for (int i = 0; i < n; i++)
            {
                if (s[i] > 90)
                    s[i] -= 32;
            }
        }
    }
    // lowercase alphabet is from 97 to 122.
    // uppercase alphabet is from 65 to 90.

    cout << s;
    return;
}
int main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
}