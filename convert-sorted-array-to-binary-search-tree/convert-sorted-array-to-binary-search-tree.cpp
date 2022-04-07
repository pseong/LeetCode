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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = nullptr;
        if (nums.size()) {
            root = new TreeNode();
            dfs(root, 0, (int)nums.size()-1, nums);
        }
        return root;
    }
    
    void dfs(TreeNode* node, int l, int r, vector<int>& nums) {
        if (r < l) return;
        int mid = l + (r - l) / 2;
        node->val = nums[mid];
        if (mid-l > 0) {
            TreeNode* left = new TreeNode();
            node->left = left;
            dfs(left, l, mid-1, nums);
        }
        if (r-mid > 0) {
            TreeNode* right = new TreeNode();
            node->right = right;
            dfs(right, mid+1, r, nums);
        }
    }
};