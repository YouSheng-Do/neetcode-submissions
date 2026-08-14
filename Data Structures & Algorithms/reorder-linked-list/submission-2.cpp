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
        // seperate two part
        // use fast and slow pointer to split it
        // make the end of first list point to nullptr

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = nullptr;

        // reverse second list
        ListNode* prev = nullptr;
        ListNode* cur = second;

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
