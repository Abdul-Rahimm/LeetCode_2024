// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool noChild(TreeNode *root)
    {
        return root->left == NULL && root->right == NULL;
    }

    void leftsum(TreeNode *root, int &value)
    {
        if (root == NULL)
            return;
        if (root->left != NULL and noChild(root->left))
            value += root->left->val;

        leftsum(root->left, value);
        leftsum(root->right, value);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        int value = 0;
        leftsum(root, value);

        return value;
    }
};