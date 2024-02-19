// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vii;
typedef array<int, 2> ii;
typedef vector<ii> vii;
const int mod = 1e9 + 7;

// learned how to construct a weighted directed graph from below question
// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

void solve();
signed main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;

    while (tc--)
        solve();

    return 0;
}

// keeping the undirected graph global
// the graph is going to contain {source, end, weight} vectors
vector<vector<int>> adj;

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

void solve()
{
    populateAdj(); // the undirected weighted graph has been filled with cities details
}