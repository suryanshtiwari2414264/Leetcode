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
    pair<bool,int>dfs(TreeNode* root,vector<int>&ans){
        if(root==NULL)
            return {true,0};
        pair<bool,int> l = dfs(root->left,ans);
        pair<bool,int> r = dfs(root->right,ans);
        if((l.first==true && r.first == true)&&(l.second == r.second)){
            int size = l.second+r.second+1;
            ans.push_back(size);
            return{true,size};
        }
        else
            return {false,0};
    }
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root,ans);
        if(ans.size()<k)
            return -1;
        sort(ans.begin(),ans.end(),greater<int>());
        return ans[k-1];
    }
};