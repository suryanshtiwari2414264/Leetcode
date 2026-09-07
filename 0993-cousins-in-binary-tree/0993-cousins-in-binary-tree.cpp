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
TreeNode* XParent = NULL;
TreeNode* YParent = NULL;
int Xdepth = -1;
int Ydepth = -1;
void dfs(TreeNode* root,int x, int y,TreeNode* parent, int depth){
    if(root == NULL)
        return;
    if(root->val==x)
    {
        XParent = parent;
        Xdepth = depth;
    }
    if(root-> val == y){
        YParent = parent;
        Ydepth = depth;
    }
    dfs(root->left,x, y,root,depth+1);
    dfs(root->right,x, y,root,depth+1);
}
public:
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root,x,y,NULL,1);//Call 
        return (XParent != YParent && Xdepth == Ydepth);
    }
};