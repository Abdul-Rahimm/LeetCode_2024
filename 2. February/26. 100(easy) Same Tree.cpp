// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

string BFS(TreeNode *root)
{
    if (root == NULL)
        return "";

    string ans = to_string(root->val);

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        // if(front == NULL)
        //     continue;

        if (front->left != NULL)
        {
            ans += to_string(front->left->val);
            q.push(front->left);
        }
        else
            ans += "N";

        if (front->right != NULL)
        {
            ans += to_string(front->right->val);
            q.push(front->right);
        }
        else
            ans += "N";
    }

    return ans;
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    string s1 = BFS(p);
    string s2 = BFS(q);

    cout << s1 << " " << s2 << endl;
    return s1 == s2;
}
