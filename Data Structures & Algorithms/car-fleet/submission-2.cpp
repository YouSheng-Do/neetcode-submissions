class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();
        vector<pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {target - position[i], (double) (target - position[i]) / speed[i]};
        }

        sort(cars.begin(), cars.end());

        stack<double> mono_st;
        for (int i = 0; i < n; ++i) {
            double t = cars[i].second;
            if (mono_st.empty() || t > mono_st.top()) {
                mono_st.push(t);
            }
        }

        return mono_st.size();
    }
};
