class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // priority_queue<pair<int, char>>, vector<pair<int, char>> pq; // maxHeap
        // select the maximum amount task
        // queue<tuple<int, char, int>> cooldown;
        // int timestamp;

        unordered_map<char, int> freq;

        for(auto t : tasks) freq[t]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>>  pq; // maxHeap
        // select the maximum amount task

        queue<tuple<int, char, int>> cooldown; // cooldown queue

        for (auto [t, f] : freq) pq.push({f, t});

        int timestamp = 0;
        while (!pq.empty() || !cooldown.empty()) {
            // any task can be add back to pq or not
            if (!cooldown.empty()) {
                auto [f, t, returnTime] = cooldown.front();
                if (returnTime < timestamp) {
                    pq.push({f, t});
                    cooldown.pop();
                }
            }

            // pick the maximum amount task
            if (!pq.empty()) {
                auto [f, t] = pq.top(); pq.pop();
                // cout << timestamp << " " << t << endl;
                if (f > 1) {
                    cooldown.push({f - 1, t, timestamp + n});
                }
            }
            timestamp++;
        }

        return timestamp;
    }
};
