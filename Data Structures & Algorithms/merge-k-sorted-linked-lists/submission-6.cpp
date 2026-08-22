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
        // divide and conquer
        // like merge sort
        // we split lists into two halves
        // recursively merge left half into one sorted list 
        // recursively merge right half into one sorted list 
        // finally merge two sorted lists into one
        // merge log k levels
        if (lists.empty()) return nullptr;
        return divide(lists, 0, lists.size() - 1);
    }
private:
    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;
        
        if (l == r) return lists[l];

        int m = l + (r - l) / 2;
        ListNode* left = divide(lists, l, m);
        ListNode* right = divide(lists, m + 1, r);
        return conquer(left, right);
    }
    ListNode* conquer(ListNode* l1, ListNode* l2) {
        ListNode dummy;
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

        return dummy.next;
    }
};
