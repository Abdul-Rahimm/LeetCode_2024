// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

bool isCousins(TreeNode *root, int x, int y)
{
    queue<TreeNode *> q;

    if (root->val == x || root->val == y || !root->left || !root->right)
        return false;
    if (root->left->val == x || root->left->val == y)
        return false;
    if (root->right->val == x || root->right->val == y)
        return false;

    q.push(root);
    vector<pair<TreeNode *, int>> parents; // parent, level

    int level = 1;
    while (!q.empty())
    {
        int nodes = q.size();

        while (nodes--)
        {
            TreeNode *current = q.front();
            q.pop();

            if (current->left)
            {
                q.push(current->left);
                if (current->left->val == x || current->left->val == y)
                {
                    parents.push_back({current, level + 1});
                }
            }
            if (current->right)
            {
                q.push(current->right);
                if (current->right->val == x || current->right->val == y)
                {
                    parents.push_back({current, level + 1});
                }
            }
            if (parents.size() == 2)
            {
                pair<TreeNode *, int> a = parents[0];
                pair<TreeNode *, int> b = parents[1];

                if (a.first != b.first && a.second == b.second)
                    return true;
                else
                    return false;
            }
        }
        level++;
    }
    return false;
}