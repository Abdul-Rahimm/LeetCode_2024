// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"

using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> mp;

    for (auto edge : edges)
    {
        int from = edge[0];
        int to = edge[1];

        mp[to].push_back(from);

        // 0
        // 1
        // 2
        // 3 --> 0, 1 has incoming edges
        // 4 --> 0, 2
        // 5 --> 3 (0, 1)
        // 6 --> 3, 4 (set)
        // 7
    }

    vector<vector<int>> answer(n);
    for (int i = 0; i < n; i++)
    {

        vector<int> values = mp[i];
        set<int> st;

        for (int i = 0; i < values.size(); i++)
        {
            st.insert(values[i]);
            for (int number : mp[values[i]])
            {
                st.insert(number);
            }
        }

        for (int number : st)
        {
            answer[i].push_back(number);
        }
    }

    return answer;
}

int main()
{
}