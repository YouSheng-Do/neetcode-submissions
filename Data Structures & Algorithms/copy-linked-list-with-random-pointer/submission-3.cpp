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

        Node* cur = head;

        unordered_map<Node*, Node*> originalToNew;
        while (cur) {
            Node* newNode = new Node(cur->val);
            originalToNew[cur] = newNode;
            cur = cur->next;
        }

        cur = head;

        while (cur) {
            Node* newNode = originalToNew[cur];
            newNode->random = originalToNew[cur->random];
            newNode->next = originalToNew[cur->next];
            cur = cur->next;
        }

        return originalToNew[head];
    }
};
