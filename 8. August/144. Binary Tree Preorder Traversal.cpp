// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void solve(vector<int> &ans, TreeNode *root)
{

    if (root == NULL)
        return;

    ans.push_back(root->val);
    solve(ans, root->left);
    solve(ans, root->right);
}

vector<int> preorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    solve(ans, root);

    return ans;
}

vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> nodes;
    stack<TreeNode *> todo;

    while (root || !todo.empty())
    {
        if (root)
        {
            nodes.push_back(root->val);
            if (root->right)
            {
                todo.push(root->right);
            }
            root = root->left;
        }
        else
        {
            root = todo.top();
            todo.pop();
        }
    }

    return nodes;
}