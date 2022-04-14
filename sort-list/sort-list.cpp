/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* before = new ListNode(-1000000, head);
        ListNode* go = head;
        while (go && go->next) {
            if (go->val > go->next->val) {
                ListNode* node = go->next;
                ListNode* find = before;
                while (true) {
                    if (find->val <= node->val && find->next->val >= node->val) {
                        go->next = node->next;
                        node->next = find->next;
                        find->next = node;
                        break;
                    }
                    find = find->next;
                }
            }
            else go = go->next;
        }
        return before->next;
    }
};