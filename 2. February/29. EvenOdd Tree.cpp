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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        int level = 0; // initially at root level

        while (!q.empty())
        {
            int nodes = q.size();
            int value = q.front()->val; // strictly inc/dec
            int nodeCount = 0;

            while (nodes--)
            {
                // process one whole level of tree
                TreeNode *front = q.front();
                int nodeValue = front->val;
                q.pop();
                nodeCount++;

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);

                if (level % 2 == 0)
                {
                    if (nodeValue % 2 == 0)
                        return false;
                    if (nodeCount == 1)
                        continue;
                    if (nodeValue <= value)
                        return false;

                    value = nodeValue;
                }
                if (level % 2 == 1)
                {
                    if (nodeValue % 2 == 1)
                        return false;
                    if (nodeCount == 1)
                        continue;
                    if (nodeValue >= value)
                        return false;

                    value = nodeValue;
                }
            }

            level++;
        }

        return true;
    }
};