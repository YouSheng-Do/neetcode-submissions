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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // use a helper function isSameTree(node1, node2) to determine whether the two trees are identical in both structure and values
        // compare every node in root with subRoot
        // iterative dfs

        if (!root) return subRoot == nullptr;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            auto top = st.top(); st.pop();

            if (isSameTree(top, subRoot)) return true;

            if (!top) continue;

            st.push(top->left);
            st.push(top->right);
        }

        return false;
    }

    bool isSameTree(TreeNode* node1, TreeNode* node2) {
        if (!node1 && !node2) return true;

        if (!node1 || !node2) return false;

        if (node1->val != node2->val) return false;
        
        return isSameTree(node1->left, node2->left) && isSameTree(node1->right, node2->right);
    }
};
