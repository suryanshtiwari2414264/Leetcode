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
    int maxsum = INT_MIN;
        int currsum;
    
    int dfs(TreeNode* root){
        if(root == nullptr)
            return 0;
        int lsum= dfs(root->left);
        int rsum= dfs(root->right);
        lsum = max(0,lsum);
        rsum = max(0,rsum);
        currsum = lsum + root->val + rsum;
        maxsum = max(maxsum,currsum);
        return root->val + (max(lsum,rsum));
    }
    int maxPathSum(TreeNode* root) {
         dfs(root);
         return maxsum ;
        
    }
};