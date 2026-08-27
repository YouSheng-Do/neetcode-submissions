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
    int diameterOfBinaryTree(TreeNode* root) {
        // longest path = max depth of node->left + max depth of node->right
        int maxLen = 0;
        depth(root, maxLen);

        return maxLen;
    }
    int depth(TreeNode* node, int& maxLen) {
        if (!node) return 0;
        int leftDepth = depth(node->left, maxLen);
        int rightDepth = depth(node->right, maxLen);
        maxLen = max(maxLen, leftDepth + rightDepth);
        return max(leftDepth, rightDepth) + 1;
    }
};
