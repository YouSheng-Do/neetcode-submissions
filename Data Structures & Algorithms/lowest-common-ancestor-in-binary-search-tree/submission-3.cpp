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
        unordered_set<TreeNode*> pathToP;
        
        dfsPath(root, p, pathToP);

        // Second
        TreeNode* LCA = nullptr;
        findLCA(root, pathToP, q, LCA);

        return LCA;
    }
    bool dfsPath(TreeNode* node, TreeNode* target, unordered_set<TreeNode*>& path) {
        if (!node) return false;
        if (node == target) {
            path.insert(node);
            return true;
        }
        if (dfsPath(node->left, target, path) ||            dfsPath(node->right, target, path)) {
            path.insert(node);
            return true;
        }
        
        return false;
    }
    bool findLCA(TreeNode* node, const unordered_set<TreeNode*>& pathToP, TreeNode* target, TreeNode*& LCA) {
        // dfs to find target
        // when we find target
        // check that from target to root this path, which node is the lowest common ancestor
        // if find we just don't update LCA

        if (!node || LCA) return false;
        if (node == target) {
            if (pathToP.count(node)) LCA = node;
            return true;
        }
        
        bool left = findLCA(node->left, pathToP, target, LCA);
        bool right = findLCA(node->right, pathToP, target, LCA);
        if ((left || right) && pathToP.count(node) && !LCA) LCA = node;

        return (left || right) && !LCA;
    }
};
