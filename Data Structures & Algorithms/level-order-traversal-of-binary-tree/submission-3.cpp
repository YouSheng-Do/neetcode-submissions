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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // top-down
        // dfs
        // stack<pair<TreeNode*, int>> st; {node, level}

        if (!root) return {};

        stack<pair<TreeNode*, int>> st;
        vector<vector<int>> ans;

        st.push({root, 1});
        while (!st.empty()) {
            auto [node, level] = st.top(); st.pop();
            if (level > ans.size()) ans.push_back({});

            ans[level - 1].push_back(node->val);

            if (node->right) st.push({node->right, level + 1});
            if (node->left) st.push({node->left, level + 1});
        }

        return ans;
    }
};
