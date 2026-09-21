class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Think of this pattern: ( left ) right
        // left is a valid parentheses string with i pairs.
        // right is a valid parentheses string with k - i - 1 pairs.
        // every valid result of k pairs can be formed by combining smaller answers
        // dp
        // for each k from 1 to n
        //   try every split from 0 to k-1
        //     for every string in dp[i] 
        //       for every string in dp[k - i - 1]
        //         "(" + dp[i] + ")" + dp[k - i - 1]
        
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
