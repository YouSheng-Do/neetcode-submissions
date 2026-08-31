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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // binary search tree maintain the property 
        // For every node, the values of all nodes in its left subtree is less than the node's value
        // and the values of all nodes in its right subtree is greater than the node's value

        // so we try to find p and q and LCA
        // for a node, if its left and right both find something, it means p and q is in its two subtree. So we return node
        // if only one side find
        
        // dfs

        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;

        return left ? left : right;
    }
};
