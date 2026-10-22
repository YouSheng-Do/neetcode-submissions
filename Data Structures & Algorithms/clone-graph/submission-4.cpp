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
        // traverse the node
        // dfs
        // copy all the node
        unordered_map<Node*, Node*> mapping;
        return dfs(mapping, node);
    }
    Node* dfs(unordered_map<Node*, Node*>& mapping, Node* cur) {
        if (!cur) return nullptr;

        if (mapping.count(cur)) return mapping[cur];

        mapping[cur] = new Node(cur->val);

        for (auto neighbor : cur->neighbors) {
            mapping[cur]->neighbors.push_back(dfs(mapping, neighbor));
        }

        return mapping[cur];
    }
};
