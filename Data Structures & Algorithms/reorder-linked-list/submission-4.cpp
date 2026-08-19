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
        reorder(head, head->next);
    }

    ListNode* reorder(ListNode* left, ListNode* right) {
        if (!right) return left;

        left = reorder(left, right->next);
        if (!left) return nullptr;

        if (left == right || left->next == right) {
            right->next = nullptr;
            return nullptr;
        }
        ListNode* new_left = left->next;
        left->next = right;
        right->next = new_left;

        return new_left;
    }
};
