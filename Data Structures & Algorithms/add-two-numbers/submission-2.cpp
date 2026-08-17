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
        return addTwoList(l1, l2, false);
    }
    ListNode* addTwoList(ListNode* l1, ListNode* l2, bool carry) {
        if (!l1 && !l2 && !carry) return nullptr;

        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int sum = val1 + val2 + carry;
        ListNode* node = new ListNode(sum % 10, 
            addTwoList(l1 ? l1->next : l1, 
                l2 ? l2->next : l2, sum / 10));
        
        return node;
    }
};
