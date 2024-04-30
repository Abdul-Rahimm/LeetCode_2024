// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    typedef long long ll;

    long long wonderfulSubstrings(string word)
    {
        unordered_map<ll, ll> mp;

        mp[0] = 1; // i have seem the 0 cum_xor at the very start
        int cum_xor = 0;

        ll result = 0;

        for (char ch : word)
        {

            // finding the shift to represent ch in binary
            int shift = ch - 'a'; // a will be shifted 0 times. b 1 times

            cum_xor ^= (1 << shift); // left shifting 1 shift times

            result += mp[cum_xor]; // for even characters

            for (char c = 'a'; c <= 'j'; c++)
            {
                shift = c - 'a';
                ll check_xor = (cum_xor ^ (1 << shift));
                result += mp[check_xor];
            }

            mp[cum_xor]++;
        }

        return result;
    }
};