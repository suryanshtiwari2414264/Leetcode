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
    void inorder(TreeNode* root,vector<int>&arr){
        if(root == NULL)
            return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* BST(vector<int>arr,int l,int h){
        if(l>h)
            return NULL;
        int mid= l+(h-l)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = BST(arr,l,mid-1);
        root->right = BST(arr,mid+1,h);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        int n = arr.size();
        return BST(arr, 0, arr.size() - 1);       
    }
};