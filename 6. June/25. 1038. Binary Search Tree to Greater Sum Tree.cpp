// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
#include

using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int solve(TreeNode *root, int &sum)
{
    if (root == NULL)
        return 0;

    if (root->right == NULL && root->left == NULL)
    {
        sum += root->val;
        root->val = sum;
        return sum;
    }

    // go right
    int right = root->val + solve(root->right, sum);

    // updating value after coming from right
    sum += root->val;
    root->val = sum;

    // go left
    int left = root->val + solve(root->left, sum);

    return max(right, left);
}

TreeNode *bstToGst(TreeNode *root)
{

    int sum = 0;
    solve(root, sum);

    return root;
}