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
        int leftSum = dfs(node->left, maxSum);
        int rightSum = dfs(node->right, maxSum);

        // consider node as the relay station
        int val = node->val;
        maxSum = max({maxSum, leftSum + val + rightSum, leftSum + val, val, rightSum + val});

        // process node
        return max(val + max(leftSum, rightSum), val);
    }
};
