class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // scan from right to left
        int n = temperatures.size();
        vector<int> res(n, 0);
        for (int i = n - 2; i >= 0; --i) {
            int next = i + 1;
            while (res[next] != 0 && temperatures[next] <= temperatures[i]) {
                next += res[next];
            }
            res[i] = temperatures[next] > temperatures[i] ? next - i : 0;
        }
        return res;
    }
};
