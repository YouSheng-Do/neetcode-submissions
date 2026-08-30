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
        // serialization of root and subRoot
        // build two vector<string> to represent the two tree
        // how to dot it ? 
        // => ues "#" to represent nullptr. Traverse two trees in same traversal(ex: preorder)
        // so now we'll have s_root and s_subRoot
        // question becomes to find if s_subRoot is a substring in s_root
        // =>we can solve it by KMP algorithm

        // serialization two trees to string
        vector<string> s_root, s_subRoot;
        serialize(root, s_root);
        serialize(subRoot, s_subRoot);

        // find s_subRoot is a contiguous pattern in s_root
        // => use z-function to solve it in linear time
        
        return z_function(s_root, s_subRoot);
    }

    void serialize(TreeNode* node, vector<string>& s) {
        if (!node) {
            s.push_back("#");
            return;
        }

        s.push_back(to_string(node->val));
        serialize(node->left, s);
        serialize(node->right, s);
    }

    bool z_function(vector<string>& text, vector<string>& pattern) {
        // pattern should be first, since we check prefix in combined
        vector<string> combined = pattern;

        combined.push_back("|");

        for (auto& s : text) combined.push_back(s);

        const int n = combined.size();
        const int m = pattern.size();

        // build a z-array 
        // z[i] represent the length of the longest string from i that match the prefix of the whole string
        // so if there's any z[i] == pattern.size(), return true;

        vector<int> z(n, 0);

        // naive way to build z-array
        // O(n^2)
        for (int i = 1; i < n; ++i) {
            while (i + z[i] < n && 
                combined[z[i]] == combined[i + z[i]]) {
                z[i]++;
                if (z[i] == m) return true;
            }
        }

        return false;
    }


};
