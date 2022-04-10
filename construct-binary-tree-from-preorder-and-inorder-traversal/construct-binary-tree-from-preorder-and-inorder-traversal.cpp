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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return make(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    
    TreeNode* make(vector<int>& preorder, int s, int e, vector<int>& inorder, int l, int r) {
        if (e<s || r<l) return nullptr;
        TreeNode* node = new TreeNode(preorder[s]);
        int idx = find(inorder.begin()+l, inorder.begin()+r+1, preorder[s]) - inorder.begin();
        int cnt = idx - l;
        node->left = make(preorder, s+1, s+cnt, inorder, l, idx-1);
        node->right = make(preorder, s+cnt+1, e, inorder, idx+1, r);
        return node;
    }
};