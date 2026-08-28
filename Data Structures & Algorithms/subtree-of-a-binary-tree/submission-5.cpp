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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // use a helper function isSameTree(node1, node2) to determine whether the two trees are identical in both structure and values
        // recursive dfs
        return dfs(root, subRoot);
    }
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if (!root) return subRoot == nullptr;
        if (isSameTree(root, subRoot)) return true;

        return dfs(root->left, subRoot) || dfs(root->right, subRoot);
    }

    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;

        if (!node1 || !node2) return false;

        if (node1->val != node2->val) return false;

        return isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
    }
};
