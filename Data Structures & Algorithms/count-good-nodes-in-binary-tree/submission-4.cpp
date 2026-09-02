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
        // find the local maximum in every path
        // top-down
        // dfs 
        // iterative
        // record the local maximum in every path
        // if node->val > local maximum, update it and count++
        return dfs(root, INT_MIN);
    }
    int dfs(TreeNode* node, int maximum) {
        if (!node) return 0;

        int res = (node->val >= maximum) ? 1 : 0;
        maximum = max(node->val, maximum);

        res += dfs(node->left, maximum);
        res += dfs(node->right, maximum);

        return res;
    }
};
