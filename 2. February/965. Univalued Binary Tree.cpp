bool isUnivalTree(TreeNode *root)
{
    unordered_set<int> st;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        st.insert(front->val);
        if (st.size() > 1)
            return false;

        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }

    return true;
}