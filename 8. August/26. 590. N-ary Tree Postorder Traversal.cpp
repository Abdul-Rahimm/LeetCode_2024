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

    for (auto child : root->children)
    {
        solve(ans, child);
    }

    ans.push_back(root->val);
}

vector<int> postorder(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;
    solve(ans, root);

    return ans;
}