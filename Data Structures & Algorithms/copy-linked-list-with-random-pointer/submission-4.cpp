/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> mapping;
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* cur = new Node(head->val);
        mapping[head] = cur;

        cur->next = copyRandomList(head->next);
        cur->random = mapping[head->random];

        return cur;
    }
};
