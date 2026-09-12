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
        // const int need=0;
        // const int covered = 1;
        // const int has_camera = 2;
        int count = 0;
        int dfs(TreeNode* root){
        if(root== nullptr)
            return 1;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if(l==-1 || r== -1){
            count ++;
            return 0;
        }
        if(l==0 || r==0)
            return 1;
        
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int rootstate = dfs(root);
        if(rootstate == -1)
            count++;
        return count;        
    }
};