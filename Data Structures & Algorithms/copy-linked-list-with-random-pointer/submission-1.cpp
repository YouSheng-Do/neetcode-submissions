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
        // use an unordered_map<Node*, Node*> OriginalToNew;
        // key->original Node*, val->new Node*

        if (!head) return nullptr;

        Node* original_cur = head;
        Node dummy(0);
        Node* cur = &dummy;

        unordered_map<Node*, Node*> originalToNew;
        while (original_cur) {
            Node* newNode = new Node(original_cur->val);
            cur->next = newNode;
            originalToNew[original_cur] = newNode;
            original_cur = original_cur->next;
            cur = cur->next;
        }

        cur = dummy.next;

        while (head) {
            cur->random = originalToNew[head->random];
            cur = cur->next;
            head = head->next;
        }

        return dummy.next;
    }
};
