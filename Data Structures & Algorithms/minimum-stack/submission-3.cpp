class MinStack {
public:
    stack<pair<int, int>> st; // val, diff
    // val - prev_min = diff;
    // val == cur_min
    // prev_min = cur_min - diff
    int cur_min;
    MinStack() {
        cur_min = INT_MAX;
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push(make_pair(val, INT_MAX));
        }
        else {
            st.push(make_pair(val, val - cur_min));
        }
        cur_min = min(cur_min, val);
        // cout << cur_min << endl;
    }
    
    void pop() {
        if (st.size() == 1) cur_min = INT_MAX;
        else if (cur_min == st.top().first) {
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
