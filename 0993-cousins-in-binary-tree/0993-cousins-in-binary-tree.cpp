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
 // DFS APPROACH
// class Solution {
// private:
// TreeNode* XParent = NULL;
// TreeNode* YParent = NULL;
// int Xdepth = -1;
// int Ydepth = -1;
// void dfs(TreeNode* root,int x, int y,TreeNode* parent, int depth){
//     if(root == NULL)
//         return;
//     if(root->val==x)
//     {
//         XParent = parent;
//         Xdepth = depth;
//     }
//     if(root-> val == y){
//         YParent = parent;
//         Ydepth = depth;
//     }
//     dfs(root->left,x, y,root,depth+1);
//     dfs(root->right,x, y,root,depth+1);
// }
// public:
//     bool isCousins(TreeNode* root, int x, int y) {
//         dfs(root,x,y,NULL,1);//Call 
//         return (XParent != YParent && Xdepth == Ydepth);
//     }
// };
// BFS APPROACH
class Solution{
public:
    bool isCousins(TreeNode* root, int x, int y){
        if(root==nullptr)
            return false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            bool sibling = false;
            bool cousins = false;
            int lvl_size = q.size();
            for(int i = 1; i<= lvl_size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node == NULL)
                {
                    sibling = false;
                }
                else
                {
                    if(node->val == x || node->val ==y)
                    {
                        if(cousins== false)
                        {
                            sibling = true;
                            cousins = true;
                        }
                        else
                        {
                            if(sibling == false)
                                return true;
                            else
                                return false;
                        }

                    }
                    if(node->left!=NULL)
                        q.push(node->left);
                    if(node->right!= NULL)
                        q.push(node->right);
                    q.push(NULL);
                }
            }
            if(cousins)
                return false;

        }
        return false;
    }
};