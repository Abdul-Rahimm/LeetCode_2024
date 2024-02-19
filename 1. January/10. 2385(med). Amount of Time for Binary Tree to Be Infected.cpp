// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int amountOfTime(TreeNode *root, int start)
{
    unordered_map<int, vector<int>> mp;

    // TreeNode* temp = root;
    vector<int> nums;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *top = q.front();
        nums.push_back(top->value);

        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);

        q.pop();
    }
}