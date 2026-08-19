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
    Node* copyRandomList(Node* head) {
        store(head);
        return copy(head);
    }
    unordered_map<Node*, Node*> mapping;
    void store(Node* head) {
        if (!head) return;

        Node* newNode = new Node(head->val);
        mapping[head] = newNode;
        store(head->next);
    }
    Node* copy(Node* head) {
        if (!head) return nullptr;

        Node* cur = mapping[head];
        cur->next = copy(head->next);
        cur->random = mapping[head->random];

        return cur;
    }
};
