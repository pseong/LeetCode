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
        return dfs(0, (int)nums.size()-1, nums);
    }
    
    TreeNode* dfs(int l, int r, vector<int>& nums) {
        if (r < l) return nullptr;
        TreeNode* node = new TreeNode();
        int mid = l + (r - l) / 2;
        node->val = nums[mid];
        
        node->left = dfs(l, mid-1, nums);
        node->right = dfs(mid+1, r, nums);
        
        return node;
    }
};