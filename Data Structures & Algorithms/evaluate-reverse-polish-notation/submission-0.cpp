class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 
        // stoi()
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
                st.push(stoi(token));
            }
        }

        return (int) st.top();
    }
    // long long stringToInt(string s){

    // }
};
