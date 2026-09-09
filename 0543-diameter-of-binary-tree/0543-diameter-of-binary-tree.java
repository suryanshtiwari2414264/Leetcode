/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    private int maxdia = 0;

    private int dfs(TreeNode root) {

        if (root == null)
            return 0;

        int l = dfs(root.left);
        int r = dfs(root.right);

        int currdia = l + r;

        maxdia = Math.max(maxdia, currdia);

        return 1 + Math.max(l, r);
    }

    public int diameterOfBinaryTree(TreeNode root) {

        dfs(root);

        return maxdia;
    }
}
