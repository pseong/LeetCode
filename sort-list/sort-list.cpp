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
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* a = sortList(head);
        ListNode* b = sortList(mid);
        return merge(a, b);
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode ans(-1000000);
        ListNode* go = &ans;
        while (a && b) {
            if (a->val < b->val) {
                go->next = a;
                a = a->next;
            }
            else {
                go->next = b;
                b = b->next;
            }
            go = go->next;
        }
        if (a) go->next = a;
        else if (b) go->next = b;
        return ans.next;
    }
    
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* ans = slow->next;
        slow->next = nullptr;
        return ans;
    }
};