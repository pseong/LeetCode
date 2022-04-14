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
    int ans = -1000000000;
    
    int dfs(TreeNode* node) {
        if (!node) return -1000000000;
        int l = dfs(node->left);
        int r = dfs(node->right);
        ans = max({ans, l, r, l+node->val, r+node->val, node->val, l+r+node->val});
        return max({l+node->val, r+node->val, node->val});
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};