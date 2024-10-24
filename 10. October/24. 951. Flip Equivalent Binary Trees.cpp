// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void DFS(TreeNode *root, unordered_map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;

    if (root->left)
        mp[root->val].push_back(root->left->val);
    if (root->right)
        mp[root->val].push_back(root->right->val);

    DFS(root->left, mp);
    DFS(root->right, mp);
}
bool flipEquiv(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    else if (!root1)
        return false;
    else if (!root2)
        return false;

    unordered_map<int, vector<int>> mp1, mp2;

    DFS(root1, mp1);
    DFS(root2, mp2);

    for (auto &row : mp1)
    {
        sort(row.second.begin(), row.second.end());
    }
    for (auto &row : mp2)
    {
        sort(row.second.begin(), row.second.end());
    }

    return mp1 == mp2;
}