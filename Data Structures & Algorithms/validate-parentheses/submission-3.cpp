class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> parentheses = {
            {')', '('}, {']', '['}, {'}', '{'}
            };
        for (auto& c : s) {
            if (!parentheses.count(c)) st.push(c);
            else {
                if (st.empty() || st.top() != parentheses[c]) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
