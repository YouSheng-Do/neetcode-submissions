class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");
        for (int i = 1; i <= n; ++i) {
            // left valid parentheses count
            for (int j = 0; j < i; ++j) {
                for (string& left : dp[j]) {
                    for (string& right : dp[i - j - 1]) {
                        string s = "(";
                        s += left;
                        s += ")";
                        s += right;
                        dp[i].push_back(s);
                    }
                }
            }
        }

        return dp[n];
    }
};
