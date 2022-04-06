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
    ListNode* left;
    
    bool go(ListNode* right) {
        if (right == nullptr) return true;
        bool b = go(right->next) & (left->val == right->val);
        left = left->next;
        return b;
    }
    bool isPalindrome(ListNode* head) {
        left = head;
        return go(head);
    }
};