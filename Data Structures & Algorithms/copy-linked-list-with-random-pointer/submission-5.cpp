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
        if (mapping.count(head)) return mapping[head];

        Node* copy = new Node(head->val);
        mapping[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = mapping[head->random];

        return copy;
    }
};
