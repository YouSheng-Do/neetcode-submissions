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
        // iterative
        // inorder
        stack<pair<TreeNode*, bool>> st; // {node, its left subtree has been visit or not}

        st.push({root, false});

        while (!st.empty()) {
            auto [node, visited] = st.top(); st.pop();
            if (visited) {
                if (--k == 0) return node->val;
                continue;
            }

            // process right first, since it's a stack
            if (node->right) st.push({node->right, false});

            st.push({node, ~visited});

            if (node->left) st.push({node->left, false});
        }

        return -1;
    }
};
