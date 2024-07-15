// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> P;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print(unordered_map<int, vector<pair<int, int>>> adj)
{

    for (auto row : adj)
    {
        int key = row.first;
        vector<pair<int, int>> pairs = row.second;

        cout << key << " : ";
        for (auto pr : pairs)
        {
            cout << "[" << pr.first << "," << pr.second << "] ";
        }
        cout << endl;
    }
}

TreeNode *createBinaryTree(vector<vector<int>> &desc)
{

    unordered_set<int> st; // push the middle elements in this
    for (vector<int> row : desc)
    {
        st.insert(row[1]);
    }

    // the remaining element is going to be the root
    int root;
    for (vector<int> row : desc)
    {
        if (st.find(row[0]) == st.end())
        {
            root = row[0];
            break;
        }
    }

    TreeNode *head = new TreeNode(root);

    // create a map for ease of access

    unordered_map<int, vector<pair<int, int>>> adj;

    for (vector<int> row : desc)
    {

        int key = row[0];
        int u = row[1];
        int v = row[2];

        adj[key].push_back({u, v});
    }

    queue<P> q;
    q.push_back({root, -1});
    int key = root;

    while ()
    {
        vector<pair<int, int>> pr = mp[key];
        for (pair<int, int> pair : pr)
            queue.push_back({pr.first, pr.second});
    }
}

TreeNode *MIK(vector<vector<int>> &descriptions)
{
    unordered_map<int, TreeNode *> mp;
    unordered_set<int> childSet; // they can never be root of the tree

    for (vector<int> &vec : descriptions)
    { // O(n)
        int parent = vec[0];
        int child = vec[1];
        int isLeft = vec[2];

        // create a parent node if doesnt exist
        if (mp.find(parent) == mp.end())
        {
            mp[parent] = new TreeNode(parent);
        }

        // create a child node if does not exist
        if (mp.find(child) == mp.end())
        {
            mp[child] = new TreeNode(child);
        }

        // place the child at the correct position of the parent in the map
        if (isLeft == 1)
        { // left child
            mp[parent]->left = mp[child];
        }
        else
        {
            mp[parent]->right = mp[child];
        }

        // insert the child in collection of all children
        childSet.insert(child);
    }

    // Find the root
    for (vector<int> &vec : descriptions)
    { // O(n)
        int parent = vec[0];
        if (childSet.find(parent) == childSet.end())
        { // if(!mp.count(parent))
            return mp[parent];
        }
    }

    return NULL; // we will never reach here
}

int main()
{
    vii desc{{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode *head = createBinaryTree(desc);
}