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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* before = new ListNode();
        ListNode* cur = before;
        int add = 0;
        while (true) {
            int sum = add;
            if (l1) sum += l1->val;
            if (l2) sum += l2->val;
            
            if (sum || l1 || l2) {
                ListNode* node = new ListNode();
                cur->next = node;
                node->val = sum % 10;
                add = sum / 10;
                cur = cur->next;
            }
            else break;
            
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return before->next;
    }
};