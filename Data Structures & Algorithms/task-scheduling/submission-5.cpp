class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // math
        //         Greedy Intuition

        // The most frequent tasks determine the minimum structure of the schedule.

        // Let:

        // maxf = maximum frequency of any task
        // maxCount = number of tasks whose frequency equals maxf

        // For a task appearing maxf times, the first maxf - 1 occurrences each require a block of length n + 1:

        // A _ _ | A _ _ | A

        // So the cooldown constraint gives the lower bound:

        // (maxf - 1) * (n + 1) + maxCount

        // maxCount is added because all tasks with the maximum frequency can occupy the last group.

        // However, if there are enough other tasks to fill all cooldown slots, then no idle time is needed. In that case, the schedule length is simply tasks.size().

        // Therefore:

        // answer = max(
        //     (int)tasks.size(),
        //     (maxf - 1) * (n + 1) + maxCount
        // );

        // Key Idea

        // The answer is the maximum of two lower bounds:

        // Every task must be executed → tasks.size()
        // The cooldown constraint imposed by the most frequent tasks → (maxf - 1) * (n + 1) + maxCount
        //     }

        vector<int> freq(26, 0);
        int maxF = 0, maxCount = 0;

        for (auto t : tasks) {
            freq[t - 'A']++;
        }

        for (int f : freq) {
            if (f == maxF) maxCount++;
            if (f > maxF) {
                maxF = f;
                maxCount = 1;
            }
        }

        return max((int)tasks.size(), (maxF - 1) * (n + 1) + maxCount);
    }
};
