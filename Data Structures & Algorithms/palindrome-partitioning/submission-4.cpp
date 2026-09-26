class Solution {
public:
    vector<vector<string>> partition(string s) {
        // backtracking + dp
        // preprocess to check every substr in s is palindrome or not
        vector<vector<string>> ans;
        vector<string> cur;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // expand from center
        // two cases : odd length and even length

        auto expand = [&](int start, int end) {
            while (start >= 0 && end < n && s[start] == s[end]) {
                dp[start][end] = true;
                start--;
                end++;
            }
        };

        for (int mid = 0; mid < n; ++mid) {
            // odd len
            expand(mid, mid);
            // even len
            expand(mid, mid + 1);
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
