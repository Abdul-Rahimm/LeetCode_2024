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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};

        vector<vector<int>> ans;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int nodes = q.size();
            vector<int> row(nodes);

            for (int i = 0; i < nodes; i++)
            {
                TreeNode *front = q.front();
                int nodeValue = front->val;
                q.pop();

                row[i] = nodeValue;

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }

            ans.push_back(row);
        }

        return ans;
    }
};