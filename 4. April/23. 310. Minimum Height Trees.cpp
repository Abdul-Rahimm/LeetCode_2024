// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int BFS(int i, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{

    int level = 1;
    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int nodes = q.size();

        while (nodes--)
        {
            int curr = q.front();
            q.pop();
            visited[curr] = true;

            for (int i : adj[curr])
            {
                if (visited[i] == false)
                    q.push(i);
            }
        }

        level++;
    }

    return level;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{

    // hit BFS from every node and return the min score
    int score = INT_MAX;
    int min_score = INT_MAX; // keeps track on the min score

    unordered_map<int, vector<int>> adj;
    vector<int> scores;
    vector<int> ans;

    for (vector<int> row : edges)
    {
        int u = row[0];
        int v = row[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        score = BFS(i, adj, visited);

        min_score = min(min_score, score);
        scores.push_back(score);
    }

    for (int i = 0; i < n; i++)
    {
        if (scores[i] == min_score)
            ans.push_back(i);
    }

    return ans;
}
