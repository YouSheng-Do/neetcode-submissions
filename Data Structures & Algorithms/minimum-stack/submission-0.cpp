class MinStack {
public:
    stack<int> st, minSt;
    // non-decreasing monotonic stack
    MinStack() {
    }
    // st [1, 2]
    // minSt [1]
    // return : 0, 2, 1
    void push(int val) {
        // push element into st
        // check if the element is <= minSt.top
        //   if <=, push into minSt
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    
    void pop() {
        // check if st.top() == minSt.top()
        // if same {
        //   pop element from both
        // }
        // else pop from st
        if (minSt.top() == st.top()) minSt.pop();
        st.pop();
    }
    
    int top() {
        // get top from st
        return st.top();
    }
    
    int getMin() {
        // get top from minSt
        return minSt.top();
    }
};
