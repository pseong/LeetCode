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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* before = new ListNode(-100000);
        for (ListNode* ln : lists) {
            merge(before, ln);
        }
        return before->next;
    }
    
    void merge(ListNode* a, ListNode* b) {
        ListNode* go = a;
        a = a->next;
        while (a && b) {
            if (a->val <= b->val) {
                go->next = a;
                a = a->next;
            }
            else {
                go->next = b;
                b = b->next;
            }
            go = go->next;
        }
        if (b) go->next = b;
        else if (a) go->next = a;
    }
};