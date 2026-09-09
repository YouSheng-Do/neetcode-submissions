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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);

        return maxSum;
    }

    int dfs(TreeNode* node, int& maxSum) {
        // postorder
        if (!node) return 0;
        
        // visit left and right child
        // if any subtree path sum < 0, we discard it
        int leftSum = max(dfs(node->left, maxSum), 0);
        int rightSum = max(dfs(node->right, maxSum), 0);

        // consider node as the relay station
        int val = node->val;
        maxSum = max(maxSum, leftSum + val + rightSum);

        // process node
        return val + max(leftSum, rightSum);
    }
};
