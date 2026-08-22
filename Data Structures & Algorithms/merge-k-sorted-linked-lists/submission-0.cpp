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
struct cmp {
    bool operator()(const ListNode* node1, const ListNode* node2) {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto& head : lists) {
            if (head) pq.push(head);
        }
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        while (!pq.empty()) {
            auto node = pq.top(); pq.pop();
            cur->next = node;
            if (node->next) pq.push(node->next);
            cur = cur->next;
        }

        return dummy->next;
    }
};
