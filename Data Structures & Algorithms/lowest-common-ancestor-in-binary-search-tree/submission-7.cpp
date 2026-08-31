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
        // iterative version
        if (p->val > q->val) swap(p, q);

        while (root) {
            if (root->val < p->val) root = root->right;
            else if (root->val > q->val) root = root->left;
            // p->val <= root->val <= q->val
            else return root;
        }

        return nullptr;
    }
};
