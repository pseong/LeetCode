/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* go = head;
        while (go) {
            int a = go->val;
            Node* node = new Node(a);
            node->next = go->next;
            go->next = node;
            go = go->next->next;
        }
        
        go = head;
        while (go) {
            if (go->random) go->next->random = go->random->next;
            go = go->next->next;
        }
        
        Node* ans = head->next;
        go = head;
        Node* go2 = head->next;
        while (go2->next) {
            go->next = go2->next;
            go2->next = go2->next->next;
            go = go->next;
            go2 = go2->next;
        }
        go->next = nullptr;
        return ans;
        // map으로도 풀이 가능 (map을 활용한게 훨 쉽다.)
    }
};