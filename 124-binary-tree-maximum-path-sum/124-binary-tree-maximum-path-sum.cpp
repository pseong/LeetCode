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
    int ans = INT_MIN;
    
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int l = max(dfs(node->left), 0);
        int r = max(dfs(node->right), 0);
        ans = max({ans, l+r+node->val});
        return node->val + max(l, r);
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};