// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void solve(vector<vector<int>> &ans, Node *root)
{

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        int nodes = q.size();
        // process all the nodes of this level
        vector<int> currentLevel;

        while (nodes--)
        {
            Node *currentNode = q.front();
            q.pop();

            currentLevel.push_back(currentNode->val);

            for (auto child : currentNode->children)
                q.push(child);
        }

        ans.push_back(currentLevel);
    }
}

vector<vector<int>> levelOrder(Node *root)
{
    if (root == NULL)
        return {};

    vector<vector<int>> ans;

    solve(ans, root);

    return ans;
}