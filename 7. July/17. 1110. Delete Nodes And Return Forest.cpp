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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* deleteNodes(TreeNode* root, unordered_set<int> st, vector<TreeNode*> &result){
        
        if(root == NULL)
            return NULL;
        
        root->left = deleteNodes(root->left, st, result);
        root->right = deleteNodes(root->right, st, result);
        
        if(st.find(root->val) != st.end()){
            
            if(root->right){
                result.push_back(root->right);
            }
            if(root->left){
                result.push_back(root->left);
            }
            
            return NULL;
        }
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        
        unordered_set<int> st(del.begin(),del.end());
        vector<TreeNode*> result;
        
        deleteNodes(root, st, result);
        
        if(st.find(root->val) == st.end())
            result.push_back(root);
        
        return result;
        
    }
};