// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_map<int, int> mp;

        for (int i : arr)
            mp[i]++;

        if (mp[0] >= 2)
            return true;

        for (int i : arr)
            if (mp.find(2 * i) != mp.end() && i != 0)
                return true;

        return false;
    }
};