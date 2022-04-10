/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int sz = q.size();
            Node* pre = nullptr;
            for (int i=0; i<sz; i++) {
                Node* node = q.front();
                q.pop();
                if (!node) continue;
                node->next = pre;
                pre = node;
                q.push(node->right);
                q.push(node->left);
            }
        }
        return root;
    }
};