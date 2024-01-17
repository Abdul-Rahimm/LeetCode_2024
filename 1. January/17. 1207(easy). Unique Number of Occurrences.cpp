// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool uniqueOccurrences(vector<int> &arr)
{

    unordered_map<int, int> mp;

    for (int &i : arr)
        mp[i]++;

    set<int> st;

    for (auto pair : mp)
    {
        if (st.find(pair.second) != st.end())
            return false;

        st.insert(pair.second);
    }

    return true;
}