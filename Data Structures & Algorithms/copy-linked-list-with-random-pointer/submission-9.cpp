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

        // copy and store new node right after the original node
        Node* cur = head;

        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        // reference from original node to find the next and random pointer for new node
        cur = head;
        while (cur) {
            if (cur->random != nullptr)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // get the copy list
        Node* new_head = head->next;
        cur = head;

        // while (cur) {
        //     if (cur->next) cur->next = cur->next->next;
        //     cur = cur->next;
        // }
        while (cur != nullptr) {
            Node* l2 = cur->next;
            cur->next = l2->next;
            if (l2->next != nullptr) {
                l2->next = l2->next->next;
            }
            cur = cur->next;
        }

        return new_head;
    }
};
