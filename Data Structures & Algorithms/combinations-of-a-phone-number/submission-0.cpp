class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        
        vector<string> ans;
        string s;

        unordered_map<char, string> mapping;

        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        backtrack(0, s, ans, mapping, digits);

        return ans;
    }
    void backtrack(int i, string& s, vector<string>& ans, unordered_map<char, string>& mapping, const string& digits) {
        if (i == digits.size()) {
            ans.push_back(s);
            return;
        }

        char digit = digits[i];
        for (auto c : mapping[digit]) {
            s.push_back(c);
            backtrack(i + 1, s, ans, mapping, digits);
            s.pop_back();
        }
    }
};
