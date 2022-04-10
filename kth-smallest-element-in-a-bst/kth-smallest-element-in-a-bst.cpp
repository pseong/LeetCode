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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 1;
        int ans = 0;
        find(root, cnt, k, ans);
        return ans;
    }
    
    void find(TreeNode* node, int& cnt, int k, int& ans) {
        if (!node) return;
        find(node->left, cnt, k, ans);
        if (cnt == k) ans = node->val;
        cnt++;
        find(node->right, cnt, k, ans);
    }
};