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

            if (nodeCount == 1)
                continue;

            if (level % 2 == 0)
            {
                if (nodeValue % 2 == 0)
                    return false;
                if (nodeValue <= value)
                    return false;

                value = nodeValue;
            }
            if (level % 2 == 1)
            {
                if (nodeValue % 2 == 1)
                    return false;
                if (nodeValue >= value)
                    return false;

                value = nodeValue;
            }
        }

        level++;
    }

    return true;
}