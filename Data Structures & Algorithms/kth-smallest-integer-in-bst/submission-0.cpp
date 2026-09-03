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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        dfs(root, k, ans);
        return ans;
    }

    void dfs(TreeNode* node, int& k, int& ans) {
        if (!node || k == 0) return;
        
        dfs(node->left, k, ans);
        
        k--;
        if (k == 0) ans = node->val;

        dfs(node->right, k, ans);

    }
};
