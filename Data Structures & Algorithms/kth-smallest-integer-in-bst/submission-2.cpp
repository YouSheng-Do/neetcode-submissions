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

    bool dfs(TreeNode* node, int& k, int& ans) {
        // return find k-th smallest element or not
        // inorder traversal
        if (!node) return false;
        
        if (dfs(node->left, k, ans)) return true;

        k--;
        if (k == 0) {
            ans = node->val;
            return true;
        }

        return dfs(node->right, k, ans);
    }
};
