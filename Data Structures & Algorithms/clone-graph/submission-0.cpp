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

        unordered_set<int> visited;
        unordered_map<int, Node*> mapping;

        // traverse the node
        // bfs
        // copy all the node
        queue<Node*> q;
        
        q.push(node);

        int val = node->val;
        mapping[val] = new Node(val);
        visited.insert(val);

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            for (auto neighbor : front->neighbors) {
                int n_val = neighbor->val;
                if (!mapping.count(n_val)) {
                    mapping[n_val] = new Node(n_val);
                }
                mapping[front->val]->neighbors.push_back(mapping[n_val]);

                if (visited.count(n_val)) continue;
                q.push(neighbor);
                visited.insert(n_val);
            }
        }

        return mapping[node->val];
    }
};
