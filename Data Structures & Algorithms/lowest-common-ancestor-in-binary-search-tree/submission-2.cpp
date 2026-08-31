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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // break it into two part
        // first, use an unordered_set to store all the seen node in the path from root to p (dfs)
        // second, use dfs to find q and check every traverse node has been seen by p or not
        // If seen, update LCA

        // First
        unordered_set<TreeNode*> seen;
        
        dfsPath(root, p, seen);

        // Second
        TreeNode* LCA = nullptr;
        findLCA(root, seen, q, LCA);

        return LCA;
    }
    bool dfsPath(TreeNode* node, TreeNode* target, unordered_set<TreeNode*>& seen) {
        if (!node) return false;
        if (node == target) {
            seen.insert(node);
            return true;
        }
        bool left = dfsPath(node->left, target, seen);
        bool right = dfsPath(node->right, target, seen);
        
        if (left || right) seen.insert(node);

        return left || right;
    }
    bool findLCA(TreeNode* node, const unordered_set<TreeNode*>& seen, TreeNode* target, TreeNode*& LCA) {
        // dfs to find target
        // when we find target
        // check that from target to root this path, which node is the lowest common ancestor
        // if find we just don't update LCA

        if (!node || LCA) return false;
        if (node == target) {
            if (seen.count(node)) LCA = node;
            return true;
        }
        
        bool left = findLCA(node->left, seen, target, LCA);
        bool right = findLCA(node->right, seen, target, LCA);
        if ((left || right) && seen.count(node) && !LCA) LCA = node;

        return (left || right) && !LCA;
    }
};
