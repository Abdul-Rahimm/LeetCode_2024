int findBottomLeftValue(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    int ans;

    while (!q.empty())
    {
        int nodes = q.size();
        int count = 0;

        while (nodes--)
        {
            TreeNode *front = q.front();
            q.pop();
            count++;

            if (count == 1)
                ans = front->val;

            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
    }

    return ans;
}