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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* even_head = even;
        if(!even || !(even->next)) return head;
        while (odd->next || even->next) {
            if (odd->next) {
                if (odd->next->next) {
                    odd->next = odd->next->next;
                    odd = odd->next;
                }
                else {
                    odd->next = nullptr;
                }
            }
            if (even->next) {
                if (even->next->next) {
                    even->next = even->next->next;
                    even = even->next;
                }
                else {
                    even->next = nullptr;
                }
            }
        }
        odd->next = even_head;
        return head;
    }
};