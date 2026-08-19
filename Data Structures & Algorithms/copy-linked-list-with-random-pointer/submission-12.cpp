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
        if (!head) return nullptr;
        // store the copy node to the original->random, and original->random is stored into copy->random
        Node* cur = head;

        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->random;
            cur->random = copy;
            cur = cur->next;
        }

        cur = head;
        while (cur) {
            Node* copy = cur->random;
            copy->random = copy->next ? copy->next->random : nullptr;
            cur = cur->next;
        }

        Node* newHead = head->random;
        cur = head;
        while (cur) {
            cur->random->next = cur->next ? cur->next->random : nullptr;
            cur = cur->next;
        }

        return newHead;
    }
};
