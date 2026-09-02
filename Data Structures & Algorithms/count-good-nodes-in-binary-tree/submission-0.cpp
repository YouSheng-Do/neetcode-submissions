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
        // dfs 
        // record the local maximum in every path
        // if node->val > local maximum, update it and count++
        int count = 0;
        dfs(root, INT_MIN, count);

        return count;
    }
    void dfs(TreeNode* node, int maximum, int& count) {
        if (!node) return;

        if (node->val >= maximum) {
            count++;
            maximum = node->val;
        }

        dfs(node->left, maximum, count);
        dfs(node->right, maximum, count);
    }
};
