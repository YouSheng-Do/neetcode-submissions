class MinStack {
public:
    stack<pair<long long, long long>> st; // val, diff
    // val - prev_min = diff;
    // val == cur_min
    // prev_min = cur_min - diff
    long long cur_min;
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            cur_min = val;
            st.push(make_pair(val, 0));
        }
        else {
            st.push(make_pair(val, val - cur_min));
            if (val < cur_min) cur_min = val;
        }
        // cout << cur_min << endl;
    }
    
    void pop() {
        if (cur_min == st.top().first) {
            cur_min -= st.top().second;
        }
        st.pop();
        // cout << cur_min << endl;
    }
    
    int top() {
        // cout << cur_min << endl;
        return st.top().first;
    }
    
    int getMin() {
        // cout << cur_min << endl;
        return cur_min;
    }
};
