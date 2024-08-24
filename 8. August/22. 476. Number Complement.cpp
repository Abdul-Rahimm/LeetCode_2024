// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int findComplement(int num)
{
    long long mul = 1;
    int ans = 0;

    while (num > 0)
    {
        int mod = num % 2;
        num /= 2;

        mod = abs(mod - 1); // reverses the bit
        ans += mod * mul;
        mul *= 2;
    }

    return ans;
}