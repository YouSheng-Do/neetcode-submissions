class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minimum = prices[0];
        int diff = 0;

        for (int p : prices) {
            minimum = min(p, minimum);
            if (p > minimum) {
                diff = max(diff, p - minimum);
            }
        }

        return diff;
    }
};
