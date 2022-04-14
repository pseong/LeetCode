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
        if (ans) return true;
        bool l = false;
        bool r = false;
        if (root->left) l = dfs(root->left, p, q);
        if (root->right) r = dfs(root->right, p, q);
        bool now = ((root->val == p) || (root->val == q)) ? true : false;
        if (ans) return true;
        if ((l&r) | (l&now) | (r&now)) ans = root;
        return l|r|now;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p->val, q->val);
        return ans;
    }
};