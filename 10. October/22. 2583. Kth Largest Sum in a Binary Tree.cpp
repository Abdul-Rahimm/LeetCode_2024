// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void solve(TreeNode *root, int k, vector<long long> &result)
{
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int nodes = q.size();
        long long sum = 0;

        while (nodes--)
        {
            TreeNode *current = q.front();
            sum += current->val;
            q.pop();

            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        result.push_back(sum);
    }

    sort(result.begin(), result.end());
}
long long kthLargestLevelSum(TreeNode *root, int k)
{
    vector<long long> result;
    solve(root, k, result);

    if (k > result.size())
        return -1;

    return result[result.size() - k];
}