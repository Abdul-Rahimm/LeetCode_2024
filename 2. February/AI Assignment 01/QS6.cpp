// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ

// learned how to construct a weighted directed graph from below question
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef pair<int, int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vii;
typedef array<int, 2> ii;
const int mod = 1e9 + 7;

// keeping the undirected graph global

vector<vector<int>> adj;    // the graph is going to contain {source, end, weight} vectors
vector<string> cities(20);  // this vector contains names of cities
vector<int> heuristics(20); // this vector contains the hueristics for all cities

void solve();
signed main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;

    while (tc--)
        solve();

    return 0;
}

// the below function will be utilized for BFS
void populateAdj()
{
    // this function basically populates the adjacency list
    // as per the question
    // I will be taking 0 in place of Arad and 1 for Bucharest... so on

    // Arad 0
    // Bucharest 1
    // Craiova 2
    // drobeta 3
    // eforie 4
    // fagaras 5
    // G 6
    // H 7
    // Iasi 8
    // L 9
    // M 10
    // N 11
    // 0 12
    // Piteshi 13
    // R 14
    // S 15
    // T 16
    // U 17
    // V 18
    // Z 19

    adj.push_back({0, 19, 75}); // means arad to zerind with cost 75
    adj.push_back({0, 16, 118});
    adj.push_back({0, 15, 140});

    adj.push_back({1, 17, 85}); // bucharest
    adj.push_back({1, 6, 90});
    adj.push_back({1, 13, 101});
    adj.push_back({1, 5, 211});

    adj.push_back({2, 13, 138}); // craiova
    adj.push_back({2, 14, 146});
    adj.push_back({2, 3, 120});

    adj.push_back({3, 2, 120}); // drobeta
    adj.push_back({3, 10, 75});

    adj.push_back({4, 7, 86}); // eforie

    adj.push_back({5, 1, 211}); // fagaras
    adj.push_back({5, 15, 99});

    adj.push_back({6, 1, 90});

    adj.push_back({7, 4, 86});
    adj.push_back({7, 17, 98});

    adj.push_back({8, 11, 87});
    adj.push_back({8, 18, 92});

    adj.push_back({9, 10, 70});
    adj.push_back({9, 16, 111});

    adj.push_back({10, 3, 75});
    adj.push_back({10, 9, 70});

    adj.push_back({11, 8, 87});

    adj.push_back({12, 19, 71});
    adj.push_back({12, 15, 151});

    adj.push_back({13, 1, 101});
    adj.push_back({13, 2, 138});
    adj.push_back({13, 14, 97});

    adj.push_back({14, 2, 146});
    adj.push_back({14, 13, 97});
    adj.push_back({14, 15, 80});

    adj.push_back({15, 0, 140});
    adj.push_back({15, 5, 99});
    adj.push_back({15, 12, 151});
    adj.push_back({15, 14, 80});

    adj.push_back({16, 0, 118});
    adj.push_back({16, 9, 111});

    adj.push_back({17, 1, 85});
    adj.push_back({17, 7, 98});
    adj.push_back({17, 18, 142});

    adj.push_back({18, 8, 92});
    adj.push_back({18, 17, 142});

    adj.push_back({19, 0, 75});
    adj.push_back({19, 12, 71});
}
void populateCities()
{
    cities[0] = "Arad";
    cities[1] = "Bucharest";
    cities[2] = "Craiova";
    cities[3] = "Drobeta";
    cities[4] = "Eforie";
    cities[5] = "Fagaras";
    cities[6] = "Giurgio";
    cities[7] = "Hirsova";
    cities[8] = "Iasi";
    cities[9] = "Luzoj";
    cities[10] = "Mehadia";
    cities[11] = "Neamt";
    cities[12] = "Oradea";
    cities[13] = "Pitesi";
    cities[14] = "Rimnieu Vilcea";
    cities[15] = "Sibui";
    cities[16] = "Timisoara";
    cities[17] = "Urziceini";
    cities[18] = "Vaslui";
    cities[19] = "Zering";
}
void fillHeuristics()
{
    heuristics[0] = 366;
    heuristics[1] = 0;
    heuristics[2] = 160;
    heuristics[3] = 242;
    heuristics[4] = 161;
    heuristics[5] = 176;
    heuristics[6] = 77;
    heuristics[7] = 151;
    heuristics[8] = 226;
    heuristics[9] = 244;
    heuristics[10] = 241;
    heuristics[11] = 234;
    heuristics[12] = 380;
    heuristics[13] = 100;
    heuristics[14] = 193;
    heuristics[15] = 253;
    heuristics[16] = 329;
    heuristics[17] = 80;
    heuristics[18] = 199;
    heuristics[19] = 374;
}
void askSourceDestination(int &source, int &destination)
{
    cout << "Please enter (0-19) Source: ";
    cin >> source;
    do
    {
        cout << "Please enter (0-19) Destination: ";
        cin >> destination;
    } while (source == destination);
    cout
        << endl
        << endl;
}
void askChoice(int &choice)
{
    cout << "Please enter choice\n0. Run all algorithms one by one and compare them\n1. BFS\n2. Uniform cost search\n3. Greedy best first Search\n4. Iterative deepening DFS\nChoice: ";
    cin >> choice;
    cout << endl;
}

void BFS(int source, int destination)
{
    // this function perfroms the BFS along with its cost in
    // in terms of operations and travelling cost

    // queue will be made
    int cost = 0;
    int n = adj.size();

    queue<P> q;                 // {node, cost}
    unordered_set<int> visited; // just so that we dont get stuck in a cycle if one exists

    q.push({source, 0}); // source se source is 0
    visited.insert(source);

    while (!q.empty())
    {
        int currentNode = q.front().first;

        for (int i = 0; i < n; i++)
        {
            vector<int> row = adj[i]; // {src, dest, cost} triples

            // we are looking for neighbours of the current node in adj
            if (row[0] != currentNode)
                continue;

            // means reached current node in adj...now add to queue
            int v = row[1];
            int rowCost = row[2];

            if (visited.find(v) == visited.end())
            {
                q.push({v, rowCost});
                visited.insert(v);

                cout << "Moving to " << cities[v] << " from " << cities[currentNode] << endl;
                cost += rowCost;
                cout << "Current cost added is " << rowCost << " and total becomes " << cost << endl;
                cout << endl;

                if (v == destination)
                {
                    cout << cities[destination] << " reached from " << cities[source] << endl;
                    cout << "Number of operations: " << visited.size() << endl;
                    cout << "Total cost incurred: " << cost << endl
                         << endl;
                    return;
                }
            }
        }

        q.pop();
    }

    // since the graph is undirected... means we can reach all nodes from all nodes
}
void uniformCostSearch(int source, int destination)
{
    priority_queue<pair<int, P>,
                   vector<pair<int, P>>,
                   greater<pair<int, P>>>
        pq; // {cost, {source, vertex}}
    unordered_set<int> visited;
    int cost = 0;

    pq.push({0, {source, source}});

    while (!pq.empty())
    {
        // {cost, {source, vertex}}
        int currentCost = pq.top().first;
        int currentNode = pq.top().second.second;
        int currentSource = pq.top().second.first;

        pq.pop();

        if (visited.find(currentNode) != visited.end())
            continue; // Skip if already visited

        visited.insert(currentNode);

        cout << "Exploring node " << cities[currentNode] << " from " << cities[currentSource] << " with cost " << currentCost << endl;

        if (currentNode == destination)
        {
            cout << endl
                 << cities[destination] << " reached from " << cities[source] << endl;
            cout << "Total cost incurred: " << currentCost << "\n";
            return;
        }

        for (const vector<int> &edge : adj)
        {
            int v = edge[1];
            int edgeCost = edge[2];

            if (edge[0] == currentNode && visited.find(v) == visited.end()) // meaning the one youre going to visit should be unvisited
            {
                // add the current edge cost to total cost
                pq.push({currentCost + edgeCost, {currentNode, v}});
            }
        }
    }
}
void greedyBestFirstSearch(int source, int destination)
{
    priority_queue<P, vector<P>, greater<P>> pq; // {heuristic, node}
    unordered_set<int> visited;

    pq.push({heuristics[source], source});

    while (!pq.empty())
    {
        int currentHeuristic = pq.top().first;
        int currentVertex = pq.top().second;
        pq.pop();

        if (visited.find(currentVertex) != visited.end())
            continue; // Skip if already visited

        visited.insert(currentVertex);

        cout << "Exploring node " << cities[currentVertex] << " with heuristic " << currentHeuristic << endl;

        if (currentVertex == destination)
        {
            cout << endl
                 << cities[destination] << " reached from " << cities[source] << endl;
            cout << "Heuristic value at destination: " << currentHeuristic << "\n";
            return;
        }

        for (const vector<int> &edge : adj)
        {
            int v = edge[1];

            if (edge[0] == currentVertex && visited.find(v) == visited.end())
            {
                pq.push({heuristics[v], v});
            }
        }
    }
}

bool dfs(int currentVertex, int destination, int depth, unordered_set<int> &visited)
{
    if (currentVertex == destination)
    {
        cout << "Destination reached from source.\n\n";
        return true;
    }

    if (depth <= 0)
    {
        return false; // Reached the depth limit
    }

    visited.insert(currentVertex);

    for (vector<int> row : adj)
    {
        if (row[0] != currentVertex)
            continue;

        int neighbor = row[1];

        if (visited.find(neighbor) == visited.end())
        {
            if (dfs(neighbor, destination, depth - 1, visited))
            {
                cout << "Went from node " << cities[currentVertex] << " to " << cities[neighbor] << endl;
                return true;
            }
        }
    }

    return false;
}
void IterativeDeepeningDFS(int source, int destination)
{
    int maxDepth = 20; // arbitrary - set to max nodes

    for (int depth = 0; depth <= maxDepth; depth++)
    {
        unordered_set<int> visited;

        cout << "Exploring at depth " << depth << ": " << endl;

        if (dfs(source, destination, depth, visited))
            return;
    }
}

void solve()
{
    int choice = -1;
    while (choice < 0 || choice > 4)
        askChoice(choice);

    int source, destination;
    askSourceDestination(source, destination);

    populateAdj(); // the undirected weighted graph has been filled with cities details
    populateCities();

    if (choice == 0)
    {
        BFS(source, destination);
        uniformCostSearch(source, destination);
        fillHeuristics(); // heuristics values for GBFS
        greedyBestFirstSearch(source, destination);
        IterativeDeepeningDFS(source, destination);
    }
    else if (choice == 1)
        BFS(source, destination);
    else if (choice == 2)
        uniformCostSearch(source, destination);
    else if (choice == 3)
    {
        fillHeuristics(); // heuristics values for GBFS
        greedyBestFirstSearch(source, destination);
    }
    else if (choice == 4)
        IterativeDeepeningDFS(source, destination);
}