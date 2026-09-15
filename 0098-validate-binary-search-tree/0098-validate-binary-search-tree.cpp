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
    bool dfs(TreeNode * root,long long low,long long high){
        if(root == nullptr)
            return true;
        if(root->val<=low || root->val>=high)
            return false;
        bool l = dfs(root->left,low,root->val);
        if(l==false)
            return false;
       bool r = dfs(root->right,root->val,high);
        if(r==false)
            return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
       return dfs(root,LLONG_MIN,LLONG_MAX);
        
    }
};