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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return {};
        map<int, vector<pair<int,int>>> mp;
        queue<tuple<TreeNode*,int,int>>q;
        q.push({root,0,0});
        while(!q.empty()){
            auto[curr,VD,depth] = q.front();
            q.pop();
            mp[VD].push_back({depth,curr->val});
            if(curr->left!= nullptr)
                q.push({curr->left,VD-1,depth+1});
            if(curr->right!= nullptr)
                q.push({curr->right,VD+1,depth+1});
            
        }

        for(auto &p:mp){
           auto &nodes = p.second;
           sort(nodes.begin(),nodes.end());
           vector<int> column;
           for(auto &x :nodes){
            column.push_back(x.second);
           }
           ans.push_back(column);
        }
        return ans;

    }
};