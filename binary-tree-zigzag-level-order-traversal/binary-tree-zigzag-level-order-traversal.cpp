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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        int dir = 1;
        vector<vector<int>> ans;
        ans.push_back({root->val});
        while (q.size()) {
            int sz = q.size();
            stack<TreeNode*> st;
            ans.push_back({});
            for (int i=0; i<sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (dir) {
                    if (node->right) ans.back().push_back(node->right->val);
                    if (node->left) ans.back().push_back(node->left->val);
                    if (node->right) st.push(node->right);
                    if (node->left) st.push(node->left);
                }
                else {
                    if (node->left) ans.back().push_back(node->left->val);
                    if (node->right) ans.back().push_back(node->right->val);
                    if (node->left) st.push(node->left);
                    if (node->right) st.push(node->right);
                }
            }
            if (ans.back().empty()) ans.pop_back();
            while (st.size()) {
                q.push(st.top());
                st.pop();
            }
            dir ^= 1;
        }
        return ans;
    }
};