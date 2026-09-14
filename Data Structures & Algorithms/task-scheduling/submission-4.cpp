class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // the maximum frequency tasks decide the minimum length of schedule
        // try to find the idle inside the length to known the length of schedule
        // Let maxf be the maximum frequency of any task 
        // idle = (maxF - 1) * n
        // for other tasks, we try to fill them in the gaps, every task can only fill maxF - 1 times
        // at the end
        // if idle is still positive, it remains some gaps => return len(tasks) + idle
        // if idle is zero or negative, it means that no idle time needed => return len(tasks)

        // ans = the length of tasks + max(0, idle)

        // for example:
        // tasks = [A,A,A,B,B,B,C,C], n = 2
        // schedule = [A, _, _, A, _, _, A], idle = 4
        // other tasks can only fill in maxF - 1
        // B : 
        // schedule = [A, B, _, A, B, _, A], idle = 2
        // C : 
        // schedule = [A, B, C, A, B, C, A], idle = 0
        // return len(tasks)

        vector<int> freq(26, 0);

        for (auto task : tasks) {
            freq[task - 'A']++;
        }

        int maxF = 0, maxIndex = -1;
        for (int i = 0; i < 26; ++i) {
            int f = freq[i];
            if (f > maxF) {
                maxF = f;
                maxIndex = i;
            }
        }

        int idle = (maxF - 1) * n;
        for (int i = 0; i < 26; ++i) {
            if (i == maxIndex) continue;
            idle -= min(freq[i], maxF - 1);
        }

        return tasks.size() + max(0, idle);
    }
};
