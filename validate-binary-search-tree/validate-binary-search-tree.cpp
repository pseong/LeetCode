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
    bool dfs(TreeNode* node, TreeNode* lo, TreeNode* hi) {
        if (!node) return true;
        if (lo && (node->val <= lo->val)) return false;
        if (hi && (node->val >= hi->val)) return false;
        return dfs(node->left, lo, node) & dfs(node->right, node, hi);
    }
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};