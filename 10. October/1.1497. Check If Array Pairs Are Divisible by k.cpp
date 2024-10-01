// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
bool canArrange(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;

    for (int i : arr)
    {
        mp[i % k]++;
    }

    for (auto row : mp)
    {
        int remainder = row.first;
        int freq = row.second;

        int otherPair = (k - remainder); // together otherPair + remainder  = k
        int pairWithZero = 0 - remainder;
        if (remainder != 0 && (mp.find(otherPair) == mp.end() || mp[otherPair] != freq) && (mp.find(pairWithZero) == mp.end() || mp[pairWithZero] != freq))
        {
            return false;
        }

        // mp.erase(otherPair);
        // mp.erase(remainder);
    }

    return true;
}

bool canArrange(vector<int> &arr, int k)
{
    vector<int> mp(k, 0); // O(K)
    // mp[r] = x
    // remainder r has frequency x

    for (int &num : arr)
    {
        int rem = (num % k + k) % k; // handling negative remainders
        mp[rem]++;
    }

    if (mp[0] % 2 != 0)
    {
        return false;
    }

    for (int rem = 1; rem <= k / 2; rem++)
    {
        int counterHalf = k - rem;
        if (mp[counterHalf] != mp[rem])
        {
            return false;
        }
    }

    return true;
}