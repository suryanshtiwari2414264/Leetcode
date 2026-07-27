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
        void inorder(TreeNode* root,vector<int> &In){
     if(root == NULL )
            return;
        inorder(root->left,In);
        In.push_back(root-> val);
        inorder(root->right,In);

        }
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> In;
      inorder(root,In);
      return In;
        
    }
};