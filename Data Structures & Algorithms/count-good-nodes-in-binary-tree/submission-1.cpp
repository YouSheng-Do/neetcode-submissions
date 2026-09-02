/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        // bfs
        // record the maximum on path with node

        queue<pair<TreeNode*, int>> q;
        int count = 0;

        q.push({root, INT_MIN});
        while (!q.empty()) {
            auto [node, maximum] = q.front(); q.pop();
            if (node->val >= maximum) {
                count++;
                maximum = node->val;
            }

            if (node->left) q.push({node->left, maximum});
            if (node->right) q.push({node->right, maximum});
        }

        return count;
    }
};
