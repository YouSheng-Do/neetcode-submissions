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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder has the mid at first
        // so we can find it in inorder and split inorder into two substree of this node

        // divide and conquer
        // find index in inorder
        // get the range of left subtree and right subtree
        // build node

        unordered_map<int, int> nodeToPos;

        int sz = inorder.size();
        for (int i = 0; i < sz; ++i) 
            nodeToPos[inorder[i]] = i;

        int index = 0;
        return buildNode(preorder, 0, sz - 1, index, inorder, nodeToPos);
    }

    TreeNode* buildNode(vector<int>& preorder, int l, int r, int& i, vector<int>& inorder, unordered_map<int, int>& nodeToPos) {
        // build cur node based on int i
        TreeNode* cur = new TreeNode(preorder[i]);

        // find cur node in inorder
        int pos = nodeToPos[preorder[i]];

        // construct leftsubtree
        if (pos > l) cur->left = buildNode(preorder, l, pos - 1, ++i, inorder, nodeToPos);

        if (pos < r) cur->right = buildNode(preorder, pos + 1, r, ++i, inorder, nodeToPos);

        return cur;
    }
};
