class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // bucket sort
        vector<int> weights(101);

        for (int& w : stones) weights[w]++;

        int sz = stones.size();

        while (sz > 1) {
            // scan from heaviest weight
            // get two heaviest each term
            int first = 0, second = 0;
            for (int w = 100; w > 0; --w) {
                if (first == 0 && weights[w] >= 2) {
                    weights[w] -= 2;
                    break;
                }
                if (weights[w]) {
                    if (first == 0) {
                        first = w;
                        weights[w]--;
                        // cout << weights[w] << endl;
                    }
                    else {
                        second = w;
                        weights[w]--;
                        // cout << weights[w] << endl;
                        break;
                    }
                }
            }
            sz -= 2;
            // cout << first << " " << second << endl;
            if (first != second) {
                weights[first - second]++;
                sz++;
            }
        }

        if (sz == 0) return 0;

        for (int w = 100; w > 0; --w) {
            if (weights[w] != 0) return w;
        }

        return 0;
    }
};
