// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        // hit bfs
        queue<TreeNode *> q;
        vector<int> vals;

        q.push(root);
        int level = 0;

        while (!q.empty())
        {
            int nodes = q.size();
            vector<int> temp;

            while (nodes--)
            {
                TreeNode *curr = q.front();
                q.pop();
                temp.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if (level % 2)
                reverse(temp.begin(), temp.end());

            for (int i : temp)
                vals.push_back(i);

            level++;
        }

        TreeNode *ans = new TreeNode(vals[0]);
        q.push(ans);
        cout << level << " " << pow(2, level - 2) << endl;

        int i = 0;
        while (i <= pow(2, level - 1) - 2)
        {
            TreeNode *temp = q.front();
            // cout << temp->val << " " << i << endl;
            q.pop();

            temp->left = new TreeNode(vals[(i * 2) + 1]);
            q.push(temp->left);
            temp->right = new TreeNode(vals[(i * 2) + 2]);
            q.push(temp->right);

            i++;
        }

        return ans;
    }
};