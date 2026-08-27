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
    bool isBalanced(TreeNode* root) {
        // recursive
        return DepthAndBalance(root).first;
    }
    pair<bool, int> DepthAndBalance(TreeNode* node) {
        // return pair<bool, int> => {its subtree of this node is balanced or not, height}

        if (!node) return {true, 0};

        auto [leftBalance, leftHeight] = DepthAndBalance(node->left);
        auto [rightBalance, rightHeight] = DepthAndBalance(node->right);

        return {leftBalance && rightBalance && (abs(leftHeight - rightHeight) <= 1), max(leftHeight, rightHeight) + 1};
    }
};
