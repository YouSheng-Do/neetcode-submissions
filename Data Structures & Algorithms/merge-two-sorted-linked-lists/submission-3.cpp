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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy = ListNode();
        ListNode* cur = &dummy;

        merge(list1, list2, cur);

        return dummy.next;
    }
    void merge(ListNode* list1, ListNode* list2, ListNode* cur) {
        // cout << cur->val << endl;
        if (!list1) {
            cur->next = list2;
            return;
        }
        if (!list2) {
            cur->next = list1;
            return;
        }

        if (list1->val < list2->val) {
            cur->next = list1;
            list1 = list1->next;
        }
        else {
            cur->next = list2;
            list2 = list2->next;
        }

        merge(list1, list2, cur->next);
    }
};
