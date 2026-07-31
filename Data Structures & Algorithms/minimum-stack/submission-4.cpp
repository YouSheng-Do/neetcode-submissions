class MinStack {
public:
    stack<long long> st;
    long long cur_min;
    MinStack() {
    }
    
    void push(int val) {
        if (st.empty()) {
            cur_min = val;
            st.push(0);
        }
        else {
            st.push(val - cur_min);
            if (val < cur_min) cur_min = val;
        }
    }
    
    void pop() {
        if (st.top() < 0) cur_min -= st.top();
        st.pop();
    }
    
    int top() {
        if (st.top() < 0) return cur_min;
        return cur_min + st.top();
    }
    
    int getMin() {
        return cur_min;
    }
};
