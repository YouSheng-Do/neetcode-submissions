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
        // dfs
        // top-down
        // iterative
        stack<pair<TreeNode*, int>> st;
        int count = 0;

        st.push({root, INT_MIN});

        while (!st.empty()) {
            auto [node, maximum] = st.top(); st.pop();

            if (node->val >= maximum) {
                count++;
                maximum = node->val;
            }

            if (node->right) st.push({node->right, maximum});
            if (node->left) st.push({node->left, maximum});
        }

        return count;
    }
};
