// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

//  Definition for a binary tree node.
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool noChild(TreeNode *root)
{
    return root->left == NULL && root->right == NULL;
}

void solve(TreeNode *root, vector<int> &nums, int num)
{
    if (root == NULL)
        return;

    num *= 10;
    num = num + root->val;

    if (noChild(root))
        nums.push_back(num);

    solve(root->left, nums, num);

    solve(root->right, nums, num);

    num -= root->val;
}

int sumNumbers(TreeNode *root)
{
    vector<int> nums;
    int num = 0;

    solve(root, nums, num);

    for (int i : nums)
    {
        num += i;
    }

    return num;
}

int main()
{
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(3);

    TreeNode *head = new TreeNode(1, left, right);
    cout << sumNumbers(head) << endl;
}