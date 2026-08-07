class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // catch
        // vector<int> time; // the time that each car needs to get the target
        // sort by their pos. Then, from the closest car to the target frist, check time_i with the largest_time so far.
        // if time_i <= largest_time, car_i will be a car_fleet and count by previous car
        // else count++, it means it will be a head of a car fleet
        // O(nlogn)
        const int n = position.size();
        vector<pair<int, double>> cars(n); // pair(pos, time)
        for (int i = 0; i < n; ++i) {
            int pos = position[i];
            int sp = speed[i];
            cars[i] = make_pair(target - pos, (double) (target - pos) / sp);
        }
        sort(cars.begin(), cars.end());
        double max_time = 0.0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            auto [_, t] = cars[i];
            if (t > max_time) {
                count++;
                max_time = t;
            }
        }
        return count;
    }
};
