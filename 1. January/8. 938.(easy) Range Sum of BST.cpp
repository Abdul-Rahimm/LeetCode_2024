// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int rangeSumBST(TreeNode *root, int low, int high)
{

    TreeNode *temp = root;
    int result = 0;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *node = q.front();
        int top = node->val;

        if (top >= low && top <= high)
            result += top;

        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);

        q.pop();
    }

    return result;
}