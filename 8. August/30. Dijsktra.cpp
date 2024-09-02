// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> P;

void populate(unordered_map<int, vector<P>> &adj)
{
    adj[1].push_back({2, 10});
    adj[1].push_back({5, 50});
    adj[1].push_back({4, 100});
    adj[1].push_back({6, 1000});
    adj[2].push_back({1, 10});
    adj[2].push_back({3, 10});
    adj[3].push_back({2, 10});
    adj[3].push_back({5, 10});
    adj[5].push_back({3, 10});
    adj[5].push_back({1, 50});
    adj[5].push_back({4, 10});
    adj[4].push_back({1, 100});
    adj[4].push_back({5, 10});
    adj[4].push_back({6, 10});
    adj[4].push_back({7, 20});

    adj[6].push_back({1, 1000});
    adj[6].push_back({4, 10});
    adj[6].push_back({7, 5});

    adj[7].push_back({6, 5});
    adj[7].push_back({4, 20});
}

void dijkstra(unordered_map<int, vector<P>> &adj, int start)
{
    int n = adj.size();
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<int> edges(n + 1, INT_MAX);

    edges[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        P current = pq.top();
        int currentNode = current.second;
        int currentCost = current.first;
        pq.pop();

        for (auto pr : adj[currentNode])
        {
            int v = pr.first;
            int cost = pr.second;

            if (edges[v] > edges[currentNode] + cost)
                pq.push({edges[currentNode] + cost, v});

            edges[v] = min(edges[v], edges[currentNode] + cost);
        }
    }

    print(1, edges);
    return;
}

int main()
{
    unordered_map<int, vector<P>> adj;
    populate(adj);

    int start = 1;

    dijkstra(adj, start);
}