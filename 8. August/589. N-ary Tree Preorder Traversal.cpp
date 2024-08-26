// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

void solve(vector<int> &ans, Node *root)
{

    if (root == NULL)
        return;

    ans.push_back(root->val);
    for (auto child : root->children)
    {
        solve(ans, child);
    }
}

vector<int> preorder(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    solve(ans, root);

    return ans;
}