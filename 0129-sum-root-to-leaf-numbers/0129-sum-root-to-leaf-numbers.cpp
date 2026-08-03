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
    void DFS(TreeNode* root, int cs,int &Root_to_leaf){
        if(root == NULL )
            return ;
        cs=cs*10+root->val;
        if(root->left == NULL && root->right== NULL)
            Root_to_leaf += cs;
            DFS(root->left,cs,Root_to_leaf);
            DFS(root->right,cs,Root_to_leaf);
    }
    int sumNumbers(TreeNode* root) {
        int Root_to_leaf=0;
        DFS(root,0,Root_to_leaf);
        return Root_to_leaf;
        
    }
};