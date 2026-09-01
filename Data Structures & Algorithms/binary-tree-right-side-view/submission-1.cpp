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
    vector<int> rightSideView(TreeNode* root) {
        // level order traversal + store the rightmost node val for every level

        // bfs

        if (!root) return {};

        queue<TreeNode*> q;
        vector<int> ans;

        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            int val = 0;
            for (int i = 0; i < sz; ++i) {
                auto node = q.front(); q.pop();
                val = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(val);
        }

        return ans;
    }
};
