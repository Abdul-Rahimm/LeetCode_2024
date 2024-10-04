// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int countPairs(vector<int> &arr)
{
    int mod = 1e9 + 7;
    unordered_map<int, int> mp;
    vector<int> powers;
    int num = 1, ans = 0, n = arr.size();
    powers.push_back(1);

    for (int i = 0; i <= 21; i++)
    {
        num <<= 1;
        powers.push_back(num);
    }

    for (int deli : arr)
    {
        for (int power : powers)
        {
            if (mp.count(power - deli))
                ans = (ans + mp[power - deli]) % mod;
        }
        mp[deli]++;
    }

    return ans;
}