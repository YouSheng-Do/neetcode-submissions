class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, r = *max_element(piles.begin(), piles.end());

        // l always false for finishEating()
        // r always true for finishEating()


        //     [0, 1, 2, ..........., *max_element]
        // l:   ^
        // r:                                ^
        // T/F:[F, F, F, T, T, ..............T]

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (finishEating(piles, m, h)) r = m;
            else l = m;
        }

        return r;
    }
    bool finishEating(const vector<int>& piles, int k, int h) {
        // return true if we can finish all the bananas in h hours with k eating-rate
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;
        }

        return hours <= h;
    }
};
