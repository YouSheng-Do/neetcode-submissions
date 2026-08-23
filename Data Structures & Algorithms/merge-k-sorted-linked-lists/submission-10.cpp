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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // divide and conquer (iteration)
        // lists[i] and lists[i + 1] // len = 1
        // lists[i] and lists[i + 2] // len = 2
        // n = len of lists
        // log (n) times
        // n = 4
        // step <= 2
        // n = 5
        // step <= 2

        int n = lists.size();
        for (int times = 0; times < (int)log2(n - 1) + 1; times++) {
            int step = (int) pow(2, times);
            for (int i = 0; i + step < n; i+=2*step) {
                mergeTwoLists(lists[i], lists[i + step]);
            }
        }

        return lists.empty() ? nullptr : lists[0];
    }
    void mergeTwoLists(ListNode* &l1, ListNode* &l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 ? l1 : l2;
        l1 = dummy.next;
        return;
    }
};
