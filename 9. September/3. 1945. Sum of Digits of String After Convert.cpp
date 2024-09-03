// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int getLucky(string s, int k)
{
    int ans = 0;

    for (char ch : s)
    {
        int value = ch - 'a' + 1;

        while (value > 0)
        {
            ans += value % 10;
            value /= 10;
        }
    }

    if (k == 1)
        return ans;

    for (int i = 1; i <= k; i++)
    {
        int copy = ans;
        ans = 0;
        while (copy > 0)
        {
            ans += copy % 10;
            copy /= 10;
        }
    }

    return ans;
}

int main()
{
    int ans = getLucky("qhquvppzooyt", 6);
    cout << ans << endl;
}