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
        queue<TreeNode*> pQueue, qQueue;

        pQueue.push(p);
        qQueue.push(q);

        while (!pQueue.empty() && !qQueue.empty()) {
            auto pFront = pQueue.front(); pQueue.pop();
            auto qFront = qQueue.front(); qQueue.pop();

            if (!pFront && !qFront) continue;
            if (!pFront || !qFront) return false;

            if (pFront->val != qFront->val) return false;

            pQueue.push(pFront->left);
            pQueue.push(pFront->right);
            qQueue.push(qFront->left);
            qQueue.push(qFront->right);
        }

        return pQueue.empty() && qQueue.empty();
    }
};
