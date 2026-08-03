class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> mono_st; // pair->first = temperature, pair->second = index
        // non-increasing monotonic stack
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int t = temperatures[i];
            while (!mono_st.empty() && t > mono_st.top().first) {
                auto [_, index] = mono_st.top(); mono_st.pop();
                res[index] = i - index;
            }
            mono_st.push(make_pair(t, i));
        }
        return res;
    }
};
