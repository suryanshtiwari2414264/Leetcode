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
    unordered_map<int, int> mp;
    int postidx;
    TreeNode* dfs(vector<int> & inorder, vector<int> & postorder,int left , int right){
        if(left>right)
            return nullptr;
        int rootval = postorder[postidx];
        postidx--;
        TreeNode* root = new TreeNode(rootval);
        int rootidx = mp[rootval];
        root->right = dfs(inorder,postorder,rootidx +1,right);
        root->left = dfs(inorder,postorder,left,rootidx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i =0; i<inorder.size();i++){
            mp[inorder[i]]=i;

        }
        postidx = postorder.size()-1;
        return dfs(inorder,postorder,0,inorder.size()-1);
        
    }
};