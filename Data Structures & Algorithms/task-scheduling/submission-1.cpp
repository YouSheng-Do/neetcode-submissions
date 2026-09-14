class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // priority_queue<pair<int, char>>, vector<pair<int, char>> pq; // maxHeap
        // select the maximum amount task
        // queue<pair<int, char>> suspendTasks;
        // unordered_map<char, int> returnTime;
        // int timestamp;

        unordered_map<char, int> freq;

        for(auto t : tasks) freq[t]++;

        priority_queue<pair<int, char>, vector<pair<int, char>>>  pq; // maxHeap
        // select the maximum amount task
        queue<pair<int, char>> suspendTasks;
        unordered_map<char, int> returnTime;
        int timestamp = 0;

        for (auto [t, f] : freq) pq.push({f, t});

        while (!pq.empty() || !suspendTasks.empty()) {
            // any task can be add back to pq or not
            if (!suspendTasks.empty()) {
                auto [f, t] = suspendTasks.front();
                if (returnTime[t] < timestamp) {
                    pq.push({f, t});
                    suspendTasks.pop();
                }
            }

            // pick the maximum amount task
            if (!pq.empty()) {
                auto [f, t] = pq.top(); pq.pop();
                // cout << timestamp << " " << t << endl;
                if (f > 1) {
                    suspendTasks.push({f - 1, t});
                    returnTime[t] = timestamp + n;
                }
            }
            timestamp++;
        }

        return timestamp;
    }
};
