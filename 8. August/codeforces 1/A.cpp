// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int num;
        cin >> num;

        if ((num >= 102 && num <= 109) || (num >= 1010 && num <= 1099))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}