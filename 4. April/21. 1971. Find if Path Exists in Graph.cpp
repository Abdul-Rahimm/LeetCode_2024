// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

unordered_map<int, vector<int>> adj;

bool DFS(int src, int dest, vector<bool> &visited)
{
    if (src == dest)
        return true;

    int curr = src;
    visited[curr] = true;
    // see where you can go from curr and visit one by one

    for (int i : adj[curr])
    {
        if (visited[i] == false && DFS(i, dest, visited))
            return true;
    }

    visited[curr] = false;
    return false;
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{

    // fill the adj
    for (vector<int> row : edges)
    {
        int u = row[0];
        int v = row[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    return DFS(source, destination, visited);
}
