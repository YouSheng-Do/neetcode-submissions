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
        // => use KMP algorithm to solve it in linear time
        
        return KMP(s_root, s_subRoot);
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
    bool KMP(const vector<string>& text, const vector<string>& pattern){
        if (pattern.empty()) return true;

        vector<int> lps = buildLps(pattern);

        const int n = text.size(), m = pattern.size();
        int i = 0; // text
        int j = 0; // pattern
        
        while (i < n) {
            if (text[i] == pattern[j]) {
                ++i;
                ++j;
                if (j == m) return true;
            }
            else if (j > 0) {
                j = lps[j - 1];
            }
            else {
                ++i;
            }
        }

        return false;
    }
    vector<int> buildLps(const vector<string>& pattern) {
        // Longest Prefix-Suffix

        // lps[i] = length of the longest proper prefix of
        // pattern[0..i] which is also a suffix

        int n = pattern.size();
        vector<int> lps(n, 0);

        int len = 0; // the length of current longest prefix-suffix and can also be index for next pos
        
        int i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                lps[i] = ++len;
                ++i;
            }
            else if (len > 0) {
                len = lps[len - 1]; // try to find shorter candicate for pattern[i], so don't move i here
            }
            else {
                lps[i] = 0;
                ++i;
            }
        }

        return lps;
    }
};
