class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;

        backtrack(cur, 0, 0, ans, n);

        return ans;
    }
    void backtrack(string& cur, int left, int right, vector<string>& ans, int n) {
        if (cur.size() == 2 * n) {
            ans.push_back(cur);
            return;
        }

        // pick left
        if (left < n) {
            cur += "(";
            backtrack(cur, left + 1, right, ans, n);
            cur.pop_back();
        }

        // pick right
        if (right < left) {
            cur += ")";
            backtrack(cur, left, right + 1, ans, n);
            cur.pop_back();
        }
    }
};
