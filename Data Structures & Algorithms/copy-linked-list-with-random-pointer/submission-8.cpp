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
        Node* cur = head;
        mapping[nullptr] = nullptr;

        while (cur) {
            if (!mapping.count(cur)) mapping[cur] = new Node(0);
            Node* copy = mapping[cur];
            copy->val = cur->val;
            if (!mapping.count(cur->next)) mapping[cur->next] = new Node(0);
            copy->next = mapping[cur->next];
            if (!mapping.count(cur->random)) mapping[cur->random] = new Node(0);
            copy->random = mapping[cur->random];
            cur = cur->next;
        }

        return mapping[head];
    }
};
