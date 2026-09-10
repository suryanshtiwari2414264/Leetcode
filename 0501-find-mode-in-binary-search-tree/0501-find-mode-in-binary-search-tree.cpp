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
    void dfs(TreeNode* root,vector<int>&arr){
        if(root == nullptr)
            return;
        dfs(root->left,arr);
        arr.push_back(root->val);
        dfs(root->right,arr);
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> arr;
        dfs(root,arr);
        vector<int> ans;
        if(arr.empty())
            return ans;
        int count=1;
        int maxcount=1;
        ans.push_back(arr[0]);
        for(int i=1;i<arr.size();i++){
            if (arr[i] == arr[i - 1]) {
                count++;
            }
            else {
                count = 1;
            }
            if (count > maxcount) {
                maxcount = count;
                ans.clear();
                ans.push_back(arr[i]);
            }
            else if (count == maxcount) {
                ans.push_back(arr[i]);
            }
        }
        return ans;   
    }
};
