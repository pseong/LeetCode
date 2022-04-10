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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (p->right) {
            TreeNode* start = p->right;
            while (start->left) start = start->left;
            return start;
        }
        
        bool b = false;
        TreeNode* ans = nullptr;
        findP(root, p, b, ans);
        return ans;
    }
    
    void findP(TreeNode* node, TreeNode* p, bool& b, TreeNode*& ans) {
        if (!node) return;
        if (node == p) {
            b = true;
            return;
        }
        findP(node->left, p, b, ans);
        if (b) {
            if (!ans && node->val > p->val) ans = node;
            return;
        }
        findP(node->right, p, b, ans);
        if (b) {
            if (!ans && node->val > p->val) ans = node;
            return;
        }
    }
};