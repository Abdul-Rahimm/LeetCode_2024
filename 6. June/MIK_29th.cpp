// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void DFS(int &ancestor, int &currentNode, unordered_map<int, vector<int>> &adj, vector<vi> &answer)
{

    for (int neighbour : adj[currentNode])
    {
        if (result[neighbour].empty() || result[neighbour].back() != ancestor)
        {
            answer[currentNode].push_back(ancestor);
            DFS(ancestor, neighbour, adj, answer);
        }
    }
}

vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    vector<vi> answer(n);

    for (auto edge : edges)
    {
        int from = edge[0];
        int to = edge[1];

        adj[from].push_back(to);
    }

    for (int i = 0; i < n; i++)
    {
        int ancestor = i;
        DFS(ancestor, i, adj, answer);
    }

    return answer;
}

int main()
{
}