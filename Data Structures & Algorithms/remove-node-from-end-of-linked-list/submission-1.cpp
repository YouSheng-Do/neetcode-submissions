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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return remove(head, n);
    }
    ListNode* remove(ListNode* head, int& n) {
        if (!head) {
            return nullptr;
        }

        head->next = remove(head->next, n);
        n--;

        if (n == 0) return head->next;

        return head;
    }
};
