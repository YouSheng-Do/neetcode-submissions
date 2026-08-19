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
    bool stop;
    void reorderList(ListNode* head) {
        stop = false;
        left = head;
        dfs(head);
    }
    void dfs(ListNode* right) {
        if (!right) return;

        dfs(right->next);

        if (stop) return;

        if (left == right || left->next == right) {
            right->next = nullptr;
            stop = true;
            return;
        }

        ListNode* new_left = left->next;
        left->next = right;
        right->next = new_left;
        left = new_left;

        return;
    }
};
