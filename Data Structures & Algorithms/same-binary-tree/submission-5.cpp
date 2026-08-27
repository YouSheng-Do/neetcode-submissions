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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // top-down
        // iterative dfs
        stack<pair<TreeNode*, TreeNode*>> st;

        st.push({p, q});

        while (!st.empty()) {
            auto [pTop, qTop] = st.top(); st.pop();

            if (!pTop && !qTop) continue;
            if (!pTop || !qTop) return false;

            if (pTop->val != qTop->val) return false;

            st.push({pTop->left, qTop->left});
            st.push({pTop->right, qTop->right});
        }

        return true;
    }
};
