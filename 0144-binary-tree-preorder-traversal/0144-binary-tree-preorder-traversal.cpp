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
    vector<int> preorderTraversal(TreeNode* root) {
        
        return Preorder(root);
    }
    vector<int> Preorder(TreeNode* root){
        
        if(root == NULL)
            return {};
        vector<int> result;
        result.push_back(root->val);

        vector<int> left = Preorder(root-> left);
        vector<int> right = Preorder(root-> right);

        result.insert(result.end(),left.begin(), left.end());
        result.insert(result.end(),right.begin(),right.end());
        return result;
    }

};