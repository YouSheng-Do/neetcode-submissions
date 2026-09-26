class Solution {
public:
    vector<vector<string>> partition(string s) {
        // backtracking + dp
        // preprocess to check every substr in s is palindrome or not
        vector<vector<string>> ans;
        vector<string> cur;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // check by len

        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                dp[start][start + len - 1] = (s[start] == s[start + len - 1] && (len <= 2 || dp[start + 1][start + len - 2]));
            }
        }

        partition(ans, cur, 0, s, dp);

        return ans;
    }
    void partition(vector<vector<string>>& ans, vector<string>& cur, int start, string& s, vector<vector<bool>>& dp) {
        if (start == s.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (dp[start][i]) {
                cur.push_back(s.substr(start, i - start + 1));
                partition(ans, cur, i + 1, s, dp);
                cur.pop_back();
            }
        }
    }
};
