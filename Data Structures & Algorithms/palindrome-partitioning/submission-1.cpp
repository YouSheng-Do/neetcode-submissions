class Solution {
public:
    vector<vector<string>> partition(string s) {
        // backtracking + dp
        vector<vector<string>> ans;
        vector<string> cur;
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        partition(ans, cur, 0, s, dp);

        return ans;
    }
    void partition(vector<vector<string>>& ans, vector<string>& cur, int start, string& s, vector<vector<bool>>& dp) {
        if (start == s.size()) ans.push_back(cur);

        for (int i = start; i < s.size(); ++i) {
            if (dp[start][i] || check(start, i, s)) {
                // cout << i << endl;
                dp[start][i] = true;
                cur.push_back(s.substr(start, i - start + 1));
                partition(ans, cur, i + 1, s, dp);
                cur.pop_back();
            }
        }
    }

    bool check(int start, int end, string& s) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};
