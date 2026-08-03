class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i = tokens.size() - 1;
        return compute(tokens, i);
    }
    int compute(vector<string>& tokens, int& i) {
        if (tokens[i].size() > 1 || isdigit(tokens[i][0])) return stoi(tokens[i]);
        auto op = tokens[i][0];
        int val2 = compute(tokens, --i);
        int val1 = compute(tokens, --i);
        if (op == '+') return val1 + val2;
        if (op == '-') return val1 - val2;
        if (op == '*') return val1 * val2;
        return val1 / val2;
    }
};
