class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (auto& token : tokens) {
            if (token.size() == 1 && !isdigit(token[0])) {
                if (st.size() < 2) return -1;
                auto val1 = st.top(); st.pop();
                auto val2 = st.top(); st.pop();
                long long res;
                switch (token[0]) {
                    case '+':
                        res = val2 + val1;
                        break;
                    case '-':
                        res = val2 - val1;
                        break;
                    case '*':
                        res = val2 * val1;
                        break;
                    case '/':
                        res = val2 / val1;
                        break;
                    default:
                        break;
                }
                st.push(res);
            }
            else {
                // st.push(stoll(token));
                st.push(stringToLL(token));
            }
        }

        return (int) st.top();
    }
    long long stringToLL(string s){
        bool negative = false;
        long long res = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '-') negative = true;
            else {
                res *= 10;
                res += s[i] - '0';
            }
        }
        return negative ? -res : res;
    }
};
