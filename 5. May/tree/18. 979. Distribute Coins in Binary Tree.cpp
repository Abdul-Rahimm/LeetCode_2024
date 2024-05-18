// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int moves = 0;
int solve(TreeNode *root)
{

    if (!root)
        return 0;

    int left = solve(root->left);
    int right = solve(root->right);

    int value = root->val + left + right;

    moves += abs(left) + abs(right);
    return value - 1;
}

int distributeCoins(TreeNode *root)
{
    solve(root);

    return moves;
}