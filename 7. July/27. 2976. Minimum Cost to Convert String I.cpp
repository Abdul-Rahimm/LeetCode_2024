// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
{

    unordered_map<char, vector<pair<char, int>>> adj;
    unordered_set<char> st; // to store the unique chars

    int n = original.size();

    for (int i = 0; i < n; i++)
    {
        char orig = original[i];
        char chan = changed[i];
        int cost_ = cost[i];

        mp[orig].push_back({chan, cost_});
        st.insert(orig);
        st.insert(chan);
    }

    vector<char> chars(st.begin(), st.end());
    // 2d matrix
    for (int i = 0; i < chars.size(); i++)
    {
    }
}

int main()
{
}