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
    TreeNode* ans = nullptr;
    
    bool dfs(TreeNode* root, int p, int q) {
        if (!root) return 0;
        bool l = dfs(root->left, p, q);
        bool r = dfs(root->right, p, q);
        bool m = (root->val == p || root->val == q) ? 1 : 0;
        if (l+r+m == 2) ans = root;
        return (l+r+m>0);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, q->val);
        return ans;
    }
};