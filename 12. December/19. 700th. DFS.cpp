class Solution
{
public:
    void DFS(unordered_map<int, vector<int>> &adj, int i, vector<bool> &vis)
    {
        // visit the current node
        vis[i] = true;

        // explore all the neighbours
        for (int ngbr : adj[i])
        {
            if (!vis[ngbr])
            {
                DFS(adj, ngbr, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {

        int n = rooms.size();

        vector<bool> vis(n, false);
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < n; i++)
        {
            vector<int> curr = rooms[i];

            for (int x : curr)
            {
                adj[i].push_back(x);
                // adj[x].push_back(i);
            }
        }

        DFS(adj, 0, vis);

        for (bool value : vis)
        {
            if (value == false)
                return false;
        }

        return true;
    }
};