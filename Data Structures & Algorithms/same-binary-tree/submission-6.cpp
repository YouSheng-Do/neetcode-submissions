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
        // bfs
        queue<pair<TreeNode*, TreeNode*>> que;

        que.push({p, q});

        while (!que.empty()) {
            auto [pFront, qFront] = que.front(); que.pop();

            if (!pFront && !qFront) continue;
            if (!pFront || !qFront) return false;

            if (pFront->val != qFront->val) return false;

            que.push({pFront->left, qFront->left});
            que.push({pFront->right, qFront->right});
        }

        return true;
    }
};
