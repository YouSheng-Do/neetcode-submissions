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
    bool isBalanced(TreeNode* root) {
        // iterative dfs
        if (!root) return true;
        
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> nodeToHeight;
        nodeToHeight[nullptr] = 0;

        st.push(root);

        while (!st.empty()) {
            auto node = st.top();
            if (node->left && !nodeToHeight.count(node->left)) {
                st.push(node->left);
            }
            else if (node->right && !nodeToHeight.count(node->right)) {
                st.push(node->right);
            }
            else {
                st.pop();
                int leftHeight = nodeToHeight[node->left];
                int rightHeight = nodeToHeight[node->right];
                if (abs(leftHeight - rightHeight) > 1) return false;
                nodeToHeight[node] = max(leftHeight, rightHeight) + 1;
            }
        }

        return true;
    }
};
