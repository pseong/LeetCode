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
        if (!root) return root;
        Node* leftmost = root;
        while (leftmost->left) {
            Node* start = leftmost;
            while (start) {
                start->left->next = start->right;
                if (start->next) {
                    start->right->next = start->next->left;
                }
                start = start->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};