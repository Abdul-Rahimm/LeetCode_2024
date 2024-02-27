// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;

int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<int, vector<int>> adj;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front->left){
                q.push(front->left);
                adj[front->val].push_back(front->left->val);
                
                adj[front->left->val].push_back(front->val);
            }
            
            if(front->right){
                q.push(front->right);
                adj[front->val].push_back(front->right->val);
                
                adj[front->right->val].push_back(front->val);
            }
        }
        
        for(auto pair: adj){
            int u = pair.first;
            vector<int> row = pair.second;
            
            cout << u << " | ";
            for(int i:row)
                cout << i << " ";
            cout << endl;
        }
        
        cout << endl;
        return 0;
    }
int main()
{
}