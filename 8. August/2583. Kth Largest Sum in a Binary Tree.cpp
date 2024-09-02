// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long solve(TreeNode *root, int k)
{

    queue<TreeNode *> q;
    priority_queue<long long> pq;
    q.push(root);

    while (!q.empty())
    {
        int nodes = q.size();
        long long sum = 0;

        while (nodes--)
        {
            TreeNode *currentNode = q.front();
            q.pop();

            // currentLevel.push_back(currentNode->val);
            sum += currentNode->val;

            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }

        pq.push(sum);
    }

    if (k > pq.size())
        return -1;

    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }

    return pq.top();
}

long long kthLargestLevelSum(TreeNode *root, int k)
{

    return solve(root, k);
}
