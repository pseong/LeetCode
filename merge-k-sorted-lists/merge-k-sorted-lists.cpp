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
        if (lists.empty()) return nullptr;
        return mergeList(lists, 0, lists.size()-1);
    }
    
    ListNode* mergeList(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        ListNode* a;
        ListNode* b;
        if (r-l > 1) {
            int mid = (l+r)/2;
            a = mergeList(lists, l, mid);
            b = mergeList(lists, mid+1, r);
        }
        else {
            a = lists[l];
            b = lists[r];
        }
        return merge(a, b);
    }
    
    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode* go = new ListNode(-100000, a);
        ListNode* ans = go;
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
        return ans->next;
    }
};