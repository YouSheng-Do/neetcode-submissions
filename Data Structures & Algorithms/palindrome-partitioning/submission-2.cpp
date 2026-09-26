class Solution {
public:
    vector<vector<string>> partition(string s) {
        // backtracking
        vector<vector<string>> ans;
        vector<string> cur;

        partition(ans, cur, 0, s);

        return ans;
    }
    void partition(vector<vector<string>>& ans, vector<string>& cur, int start, string& s) {
        if (start == s.size()) {
            ans.push_back(cur);
            return;
        }

        for (int i = start; i < s.size(); ++i) {
            if (check(start, i, s)) {
                // cout << i << endl;
                cur.push_back(s.substr(start, i - start + 1));
                partition(ans, cur, i + 1, s);
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
