// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void printAdj(map<int, vector<int>> &adj)
{
    for (auto row : adj)
    {
        int key = row.first;
        vector<int> values = row.second;

        cout << key << " : ";
        for (int i : values)
            cout << i << " ";
        cout << endl;
    }
}
bool isReachableDFS(map<int, vector<int>> &adj, int u, int v)
{
    // DFS
    if (u == v)
        return true;

    // where can i go from u(Current node)
    for (int ngbr : adj[u])
    {
        // early return
        if (isReachableDFS(adj, ngbr, v) == true)
            return true;
    }

    return false;
}
bool isReachableBFS(map<int, vector<int>> &adj, int u, int v)
{
    queue<int> q;
    q.push(u);

    while (!q.empty())
    {
        int curr = q.front(); // 1
        q.pop();
        if (curr == v)
            return true; //

        // where can i go from u
        for (int ngbr : adj[curr])
        {
            q.push(ngbr);
        }
    }

    return false;
}
void printLevelOrder(map<int, vector<int>> &adj, int start)
{
    queue<int> q;
    q.push(start);
    int level = 1; // 3

    while (!q.empty())
    {
        //    | 6 7 8 |
        int NodesInCurrentLevel = q.size(); // 3
        cout << level << " : ";

        for (int i = 0; i < NodesInCurrentLevel; i++)
        {
            int curr = q.front(); // 5
            cout << curr << ", ";
            q.pop();

            for (int ngbr : adj[curr])
            {
                q.push(ngbr);
            }
        }

        level++;
        cout << endl;
    }
}
// create a graph representation
// print the DFS traversal
int main()
{
    map<int, vector<int>> adj;

    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[1].push_back(5);
    adj[2].push_back(6);
    adj[2].push_back(7);
    adj[5].push_back(8);
    adj[8].push_back(9);

    int src = 1;
    int tar = 8; // NO

    // modular
    printLevelOrder(adj, 1);
}