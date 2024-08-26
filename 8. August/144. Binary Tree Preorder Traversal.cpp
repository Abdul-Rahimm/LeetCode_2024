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