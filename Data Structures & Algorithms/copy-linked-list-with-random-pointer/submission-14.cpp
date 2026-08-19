// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;
    
//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };
// */

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         // use an unordered_map<Node*, Node*> OriginalToNew;
//         // key->original Node*, val->new Node*

//         if (!head) return nullptr;

//         Node* cur = head;

//         unordered_map<Node*, Node*> originalToNew;
//         while (cur) {
//             Node* newNode = new Node(cur->val);
//             originalToNew[cur] = newNode;
//             cur = cur->next;
//         }

//         cur = head;

//         while (cur) {
//             Node* newNode = originalToNew[cur];
//             newNode->random = originalToNew[cur->random];
//             newNode->next = originalToNew[cur->next];
//             cur = cur->next;
//         }

//         return originalToNew[head];
//     }
// };
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
        unordered_map<Node*, Node *> mp ;
        queue <Node*> org , cop;
        org.push(head);
        Node* ans = new Node(head->val);
        mp[head] = ans;
        // ans->val = head->val;
        cop.push(ans);
        while (!org.empty()){
            Node* curr = org.front(); org.pop();
            Node* copy = cop.front(); cop.pop();
            if (mp.count(curr->next)){
                copy->next = mp[curr->next];
            }
            else if (curr->next){
                Node* temp = new Node(curr->next->val);
                mp[curr->next] = temp;
                copy->next = temp;
                // temp->val = curr->next->val;
                org.push(curr->next); cop.push(temp);
            }
            if (mp.count(curr->random)){
                copy->random = mp[curr->random];
            }
            else if (curr->random){
                Node* temp = new Node(curr->random->val);
                mp[curr->random] = temp;
                copy->random = temp;
                // temp->val = curr->random->val;
                org.push(curr->random); cop.push(temp);
            }
        }
        return ans;

    }
};
