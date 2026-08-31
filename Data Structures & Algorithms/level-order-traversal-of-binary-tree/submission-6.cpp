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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // top-down
        // dfs
        // recursive

        vector<vector<int>> ans;

        dfs(root, 0, ans);

        return ans;
    }
    void dfs(TreeNode* node, int depth, vector<vector<int>>& res) {
        if (!node) return;

        if (depth == res.size()) res.push_back({});

        res[depth].push_back(node->val);

        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }
};
