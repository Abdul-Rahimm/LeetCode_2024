// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int checkPalindrome(vector<int> &freq)
{

    int even = 0, odd = 0;

    for (int i : freq)
    {
        // count the frequencies
        if (i % 2)
            odd++;
    }

    if (odd <= 1)
    {
        return 1;
    }

    return 0;
}

int solve(TreeNode *root, vector<int> &freq)
{

    int value = root->val;
    freq[value]++;

    if (root->left == NULL && root->right == NULL)
    {
        // leaf node
        // meaning no children

        int ifPalindrome = checkPalindrome(freq);
        freq[value]--;
        return ifPalindrome;
    }

    int left = 0;
    if (root->left != NULL)
        left = solve(root->left, freq);

    int right = 0;
    if (root->right != NULL)
        right = solve(root->right, freq);

    freq[value]--;
    return left + right;
}

int pseudoPalindromicPaths(TreeNode *root)
{

    vector<int> freq(10, 0); // containing 0-10
    return solve(root, freq);
}
