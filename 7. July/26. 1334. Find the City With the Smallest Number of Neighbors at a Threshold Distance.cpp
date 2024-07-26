// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include "../utils.h"
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

typedef pair<int, int> P;

void makeAdjacencyList(unordered_map<int, vector<P>> &mp, vector<vector<int>> &edges)
{

    for (vector<int> row : edges)
    {
        int u = row[0];
        int v = row[1];
        int dist = row[2];

        mp[u].push_back({v, dist});
        mp[v].push_back({u, dist});
    }
}
void dijkstra(vector<int> &matrixRow, int src, unordered_map<int, vector<P>> &adj)
{
    matrixRow[src] = 0;                          // distance of source to source is 0
    priority_queue<P, vector<P>, greater<P>> pq; // min heap
    pq.push({0, src});

    while (!pq.empty())
    {

        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (pair<int, int> row : adj[node])
        {

            int neighbour = row.first;
            int n_dist = row.second;

            if (dist + n_dist < matrixRow[neighbour])
            {
                // have found a way with less cost
                matrixRow[neighbour] = dist + n_dist;
                pq.push({dist + n_dist, neighbour});
            }
        }
    }
}
int solve(vector<vector<int>> &matrix, int dist)
{

    int answer;
    int newCount = INT_MAX;
    for (int i = 0; i < matrix.size(); i++)
    {

        int count = 0;
        vector<int> row = matrix[i];
        for (int num : row)
        {
            if (num <= dist)
                count++;
        }

        if (count <= newCount)
        {
            newCount = count;
            answer = i;
        }
    }

    return answer;
}
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> matrix(n);
    unordered_map<int, vector<P>> mp;

    makeAdjacencyList(mp, edges);

    for (int i = 0; i < n; i++)
    {
        vector<int> row(n, INT_MAX);
        dijkstra(row, i, mp);
        matrix[i] = row;
    }
    int answer = solve(matrix, distanceThreshold);

    return 0;
}

int main()
{

    vector<vector<int>> edges{{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int answer = findTheCity(4, edges, 4);
    cout << answer << endl;
}