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
    bool isLeaf(TreeNode *root)
    {
        return !root->left && !root->right;
    }

    bool solve(TreeNode *root)
    {
        if (isLeaf(root))
        {
            if (root->val == 1)
                return true;

            return false;
        }

        bool left = solve(root->left);
        bool right = solve(root->right);

        if (root->val == 2)
            return left || right;

        return left && right;
    }

    bool evaluateTree(TreeNode *root)
    {
        return solve(root);
    }
};