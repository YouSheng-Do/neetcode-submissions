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

        // dfs
        // recursive
        vector<int> ans;

        dfs(root, 0, ans);

        return ans;
    }

    void dfs(TreeNode* node, int depth, vector<int>& ans) {
        if (!node) return;

        if (depth == ans.size()) ans.push_back({});

        ans[depth] = node->val;

        dfs(node->left, depth + 1, ans);
        dfs(node->right, depth + 1, ans);
    }
};
