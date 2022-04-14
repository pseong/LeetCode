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
        vector<int> v;
        ListNode* go = head;
        while (go) {
            v.push_back(go->val);
            go = go->next;
        }
        sort(v.begin(), v.end());
        ListNode* ans = new ListNode();
        go = ans;
        for (int i=0; i<v.size(); i++) {
            ListNode* node = new ListNode(v[i]);
            go->next = node;
            go = go->next;
        }
        return ans->next;
    }
};