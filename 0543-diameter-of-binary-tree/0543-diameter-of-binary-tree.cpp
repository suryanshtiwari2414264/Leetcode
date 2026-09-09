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
private:
    int dfs(TreeNode* root,int & maxdia){
        if(root == nullptr)
            return 0;
        int l=dfs(root->left,maxdia);
        int r=dfs(root->right,maxdia);
        int currdia = l+r;
        maxdia = max(maxdia,currdia);
        return 1+max(l,r);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxdia =0;
        dfs(root,maxdia);
        return maxdia;

    }
};