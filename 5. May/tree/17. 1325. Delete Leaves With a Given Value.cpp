// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

TreeNode *removeLeafNodes(TreeNode *root, int target)
{
    if (!root)
    {
        return NULL;
    }

    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);

    if (root->left == NULL && root->right == NULL && root->val == target)
        return NULL;

    return root;
}