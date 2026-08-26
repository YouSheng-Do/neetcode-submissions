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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // divide this prolbem into reverse k-group linked list to the end
        // seperate each k-length linkedlist
        // reverse all of them
        // connect it back
        // how to get k-lenght linked list
        // =>fast & slow pointer

        if (k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* cur = &dummy;

        while (slow && fast) {
            int groups = k;
            while (--groups && fast->next) {
                fast = fast->next;
            }
            if (groups != 0) {
                cur->next = slow;
                break;
            }
            ListNode* next = fast->next;
            cur->next = reverse(slow, fast);
            cur = slow;
            slow = next;
            fast = next;
        }

        return dummy.next;
    }

    ListNode* reverse(ListNode* cur, ListNode* end) {
        if (cur == end) return cur;
        
        ListNode* head = reverse(cur->next, end);
        cur->next->next = cur;
        cur->next = nullptr;
        
        return head;
    }
};
