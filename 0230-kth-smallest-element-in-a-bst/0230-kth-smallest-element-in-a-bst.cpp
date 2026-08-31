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
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> ans;
//         inorder(root,ans);
//         return ans[k-1];
//     }
//     void inorder(TreeNode* root, vector<int>&ans){
//         if(root == NULL){
//             return;//BASE CASE
//         }
//         inorder(root->left,ans);//LEFT
//         ans.push_back(root->val);//NODE
//         inorder(root->right,ans);//RIGHT
//     }
// };

//2nd APPROACH
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        stack<TreeNode*>st;
        TreeNode* curr= root;
        while(curr!=NULL || !st.empty())
        {
            while(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            k--;
            if(k==0)
                return curr->val;
            curr = curr->right;
        }
        return -1;
    }

};

//3rd APPROACH
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k){
        

//     }

// };