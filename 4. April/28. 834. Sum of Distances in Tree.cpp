// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int BFS_brute_force(int i, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{
    int sum = 0;
    int level = 1;

    queue<int> q;
    q.push(i);

    while (!q.empty())
    {
        int nodes = q.size();

        while (nodes--)
        {
            int front = q.front();
            q.pop();
            visited[front] = true;

            for (int addNode : adj[front])
            {
                if (visited[addNode] == false)
                    q.push(addNode),
                        sum += level;
            }
        }
        level++;
    }

    return sum;
}

vector<int> sumOfDistancesInTree_BFS_BruteForce(int n, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;

    for (vector<int> row : edges)
    {
        int u = row[0];
        int v = row[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // hit bfs for every node
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(n, false);
        ans[i] = BFS(i, adj, visited);
    }

    return ans;
}
