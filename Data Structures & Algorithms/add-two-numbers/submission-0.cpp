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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (l1 || l2 || carry) {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + (int)carry;
            carry = (sum >= 10);
            ListNode* tmp = new ListNode(sum % 10);
            cur->next = tmp;
            cur = cur->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return dummy.next;
    }
};
