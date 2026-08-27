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
        stack<TreeNode*> pStack, qStack;

        pStack.push(p);
        qStack.push(q);

        while (!pStack.empty() && !qStack.empty()) {
            auto pTop = pStack.top(); pStack.pop();
            auto qTop = qStack.top(); qStack.pop();

            if (!pTop && !qTop) continue;
            if (!pTop || !qTop) return false;

            if (pTop->val != qTop->val) return false;

            pStack.push(pTop->left);
            pStack.push(pTop->right);
            qStack.push(qTop->left);
            qStack.push(qTop->right);
        }

        return pStack.empty() && qStack.empty();
    }
};
