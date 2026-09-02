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
        // check every node is valid or not
        // valid node 
        // node->val > the maximum of left subtree and node->val < the minimum of right subtree

        return get<0>(dfs(root));
    }

    tuple<bool, int, int> dfs(TreeNode* node) {
        // return val = {is node valid, {maximum of left subtree, minimum of right subtree}}
        if (!node) return {true, INT_MIN, INT_MAX};

        // postorder
        auto [left_valid, left_max, left_min] = dfs(node->left);
        auto [right_valid, right_max, right_min] = dfs(node->right);

        bool valid = left_valid && right_valid && (node->val > left_max) && node->val < right_min;

        return {valid, max(right_max, node->val), min(left_min, node->val)};
    }
};
