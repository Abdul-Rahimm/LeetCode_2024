// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int main()
{
    vector<vector<int>> graph{{1, 2, 10}, {2, 3, 10}, {1, 4, 30}, {4, 5, 20}, {2, 4, 5}, {3, 4, 3}};

    map<int, vector<pair<int, int>>> adj;

    // populate adj
    for (vector<int> edge : graph)
    {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
}