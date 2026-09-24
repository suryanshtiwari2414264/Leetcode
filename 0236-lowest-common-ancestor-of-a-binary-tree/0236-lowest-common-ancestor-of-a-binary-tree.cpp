/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr )
            return nullptr;
        unordered_map<TreeNode* , TreeNode*>parent;
        queue<TreeNode*>que;
        parent[root] = nullptr;
        que.push(root);
        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            if(curr->left){
                parent[curr->left]=curr;
                que.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]= curr;
                que.push(curr->right);
            }
        }
        unordered_set<TreeNode*> ancestor;
        while(p!= nullptr){
            ancestor.insert(p);
            p = parent[p];
        }
        while(q!= nullptr){
            if(ancestor.find(q)!= ancestor.end())
                return q;
            q= parent[q];
        }
        return nullptr;
    }
};