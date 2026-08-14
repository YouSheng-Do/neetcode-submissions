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
    bool hasCycle(ListNode* head) {
        // two pointer
        // quick pointer + slow pointer
        // quick pointer go two steps every term
        // slow pointer go one step every term
        // if they meet, has cycle
        // else return false

        if (!head) return false;

        ListNode* quick = head->next;
        ListNode* slow = head;

        while (quick && slow) {
            if (quick == slow) return true;
            if (!quick->next) quick = nullptr;
            else quick = quick->next->next;
            slow = slow->next;
        }

        return false;
    }
};
