class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back();

        if (token != "+" && token != "-" && 
                token != "*" && token != "/")
                return stoi(token);

        int val2 = evalRPN(tokens);
        int val1 = evalRPN(tokens);

        if (token == "+") return val1 + val2;
        if (token == "-") return val1 - val2;
        if (token == "*") return val1 * val2;
        if (token == "/") return val1 / val2;
    }
};
