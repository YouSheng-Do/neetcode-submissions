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
    void reorderList(ListNode* head) {
        // get size of linked-list
        int n = 0;
        ListNode* cur = head;

        while (cur) {
            ++n;
            cur = cur->next;
        }

        if (n <= 2) return;
        
        // seperate to two part
        // first list is from start to (n + 1) / 2 - 1, len = (n + 1) / 2
        // second list is from index (n + 1) / 2 to end, len = n - (n + 1) / 2
        int half = (n + 1) / 2;

        ListNode* first = head;
        int i = 0;
        cur = head;
        while (i < half - 1) {
            ++i;
            cur = cur->next;
        }
        ListNode* second = cur->next;
        cur->next = nullptr;

        // reverse second list
        ListNode* prev = nullptr;
        cur = second;

        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        second = prev;

        // insert second list element into first list

        cur = first;
        while (second) {
            ListNode* next = second->next;
            second->next = cur->next;
            cur->next = second;
            cur = cur->next->next;
            second = next;
        }

        return;
    }
};
