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
    TreeNode* invertTree(TreeNode* root) {
        // bfs
        if (!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto front = q.front(); q.pop();
            TreeNode* right = front->right;
            front->right = front->left;
            front->left = right;
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        return root;
    }
};
