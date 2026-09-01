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
        // iterative
        // stack<pair<TreeNode*, int>> st; {node, depth}

        if (!root) return {};

        stack<pair<TreeNode*, int>> st;
        vector<vector<int>> ans;

        st.push({root, 0});
        while (!st.empty()) {
            auto [node, depth] = st.top(); st.pop();
            if (depth == ans.size()) ans.push_back(vector<int>());

            ans[depth].push_back(node->val);

            if (node->right) st.push({node->right, depth + 1});
            if (node->left) st.push({node->left, depth + 1});
        }

        return ans;
    }
};
