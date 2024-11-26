// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
public:
    void DFS(int key, unordered_map<int, vector<int>> &mp, vector<bool> &vis)
    {

        vis[key] = true;

        for (int child : mp[key])
        {
            if (vis[child] == false)
            {
                DFS(child, mp, vis);
            }
        }
    }

    int findChampion(int number, vector<vector<int>> &edges)
    {

        int n = edges.size();
        int ans = -1;
        unordered_map<int, vector<int>> mp;

        if (number == 1)
            return 0;

        for (vector<int> edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            mp[a].push_back(b);
        }

        int champs = 0;
        for (int i = 0; i < number; i++)
        {
            int key = i;

            vector<bool> visited(number, false);

            DFS(key, mp, visited);

            bool status = true;
            for (int i = 0; i < number; i++)
            {
                if (visited[i] == false)
                {
                    status = false;
                    break;
                }
            }

            if (status)
            {
                ans = key;
                champs++;
            }
        }

        return champs == 1 ? ans : -1;
    }
};