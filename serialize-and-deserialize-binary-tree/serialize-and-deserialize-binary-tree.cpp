/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void my_serialize(TreeNode* node, string& s) {
        if (!node) {
            s += "null,";
            return;
        }
        s += to_string(node->val) + ",";
        my_serialize(node->left, s);
        my_serialize(node->right, s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        my_serialize(root, ans);
        return ans;
    }

    TreeNode* my_deserialize(vector<string>& v, int& idx) {
        // if (idx >= v.size()) return nullptr;
        if (v[idx] == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(v[idx]));
        node->left = my_deserialize(v, ++idx);
        node->right = my_deserialize(v, ++idx);
        return node;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> v;
        string pool;
        for (int i=0; i<data.size(); i++) {
            if (data[i] != ',') {
                pool.push_back(data[i]);
            }
            else {
                v.push_back(pool);
                pool = "";
            }
        }
        
        int idx = 0;
        return my_deserialize(v, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));