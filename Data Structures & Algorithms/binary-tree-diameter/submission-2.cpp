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
    int diameterOfBinaryTree(TreeNode* root) {
        // iterative dfs
        // post-order traversal
        stack<TreeNode*> st; // node
        unordered_map<TreeNode*, pair<int, int>> nodeInfo; // {height, best_diameter_so_far}
        nodeInfo[nullptr] = {0, 0};

        st.push(root);
        while (!st.empty()) {
            auto node = st.top();
            if (node->left && !nodeInfo.count(node->left)) {
                st.push(node->left);
            }
            else if (node->right && !nodeInfo.count(node->right)) {
                st.push(node->right);
            }
            else {
                st.pop();
                auto [leftHeight, leftDiameter] = nodeInfo[node->left];
                auto [rightHeight, rightDiameter] = nodeInfo[node->right];
                nodeInfo[node] = {max(leftHeight, rightHeight) + 1, max({leftHeight + rightHeight, leftDiameter, rightDiameter})};
            }
        }

        return nodeInfo[root].second;
    }
};
