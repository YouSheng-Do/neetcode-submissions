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
    bool isValidBST(TreeNode* root) {
        // bfs
        queue<tuple<TreeNode*, int, int>> q; // {node, left boundary, right boundary}

        q.push({root, INT_MIN, INT_MAX});
        while(!q.empty()) {
            auto [node, left, right] = q.front(); q.pop();
            int val = node->val;
            if (val <= left || val >= right) return false;
            if (node->left) q.push({node->left, left, val});
            if (node->right) q.push({node->right, val, right});
        }

        return true;
    }
};
