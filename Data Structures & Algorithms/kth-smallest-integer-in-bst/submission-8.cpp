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
        // iterative inorder traversal
        // think from recursive version
        // three part:
        // inorder(node) {
        //     inorder(left)
        //     process(node)
        //     inorder(right)
        // }

        TreeNode* cur = root;
        stack<TreeNode*> st;

        while (cur || !st.empty()) {
            // inorder(left)
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            // return from left subtree recursion
            cur = st.top(); st.pop();

            // process node
            if (--k == 0) return cur->val;

            // inorder(right)
            cur = cur->right;
        }

        return -1;
    }
};
