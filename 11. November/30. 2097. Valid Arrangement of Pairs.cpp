// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, deque<int>> mp;
        unordered_map<int, int> inDegree, outDegree;

        for (vector<int> row : pairs)
        {
            int u = row[0];
            int v = row[1];

            mp[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // start with the node which has outDegree one more than the inDegree
        int start = -1;
        for (auto row : outDegree)
        {
            int node = row.first;
            int out = row.second;

            if (out - inDegree[node] == 1)
            {
                start = node;
                break;
            }
        }

        if (start == -1)
            for (auto row : outDegree)
            {
                int node = row.first;
                start = node;
                break;
            }

        stack<int> st;
        st.push(start);
        vector<int> ans;

        function<void()> DFS = [&]()
        {
            while (!st.empty())
            {
                int curr = st.top();

                if (!mp[curr].empty())
                {
                    int ngbr = mp[curr].back();
                    mp[curr].pop_back();
                    st.push(ngbr);
                }
                else
                {
                    ans.push_back(curr);
                    st.pop();
                }
            }
        };

        DFS();

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        vector<vector<int>> result;
        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size() - 1; i++)
        {
            result.push_back({ans[i], ans[i + 1]});
        }

        return result;
    }
};