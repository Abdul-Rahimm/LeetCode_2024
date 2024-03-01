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
    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int level = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int nodes = q.size();
            level++;

            while (nodes--)
            {
                TreeNode *front = q.front();
                q.pop();

                bool child = false;

                if (front->left)
                {
                    q.push(front->left);
                    child = true;
                }
                if (front->right)
                {
                    q.push(front->right);
                    child = true;
                }

                if (!child)
                    return level;
            }
        }
        return 0;
    }

    int minDepth(TreeNode *root)
    {

        return solve(root);
    }
};