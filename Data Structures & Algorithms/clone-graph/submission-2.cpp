/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;


        // traverse the node
        // bfs
        // copy all the node
        unordered_map<Node*, Node*> mapping;
        queue<Node*> q;
        
        q.push(node);

        int val = node->val;
        mapping[node] = new Node(val);

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (auto neighbor : cur->neighbors) {
                int n_val = neighbor->val;
                if (!mapping.count(neighbor)) {
                    mapping[neighbor] = new Node(n_val);
                    q.push(neighbor);
                }
                mapping[cur]->neighbors.push_back(mapping[neighbor]);
            }
        }

        return mapping[node];
    }
};
