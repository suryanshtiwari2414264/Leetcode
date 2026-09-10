/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:

    void dfs(TreeNode* root, vector<int>& arr) {

        if (root == nullptr)
            return;

        dfs(root->left, arr);

        arr.push_back(root->val);

        dfs(root->right, arr);
    }

public:

    vector<int> findMode(TreeNode* root) {

        vector<int> arr;

        dfs(root, arr);

        vector<int> ans;

        if (arr.empty())
            return ans;

        int count = 1;
        int maxCount = 1;

        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {

            // Same value
            if (arr[i] == arr[i - 1]) {
                count++;
            }

            // New value
            else {
                count = 1;
            }

            // New maximum frequency
            if (count > maxCount) {

                maxCount = count;

                ans.clear();

                ans.push_back(arr[i]);
            }

            // Another value with same maximum frequency
            else if (count == maxCount) {

                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};