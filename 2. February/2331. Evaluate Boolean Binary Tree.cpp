bool solve(TreeNode *root)
{
    if (root->val == 0)
        return false;
    else if (root->val == 1)
        return true;

    if (root->val == 2)
        return solve(root->left) || solve(root->right);
    else
        return solve(root->left) && solve(root->right);

    return false;
}

bool evaluateTree(TreeNode *root)
{

    return solve(root);
}