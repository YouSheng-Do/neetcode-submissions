class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // use an unordered_set to record seen numbers
        unordered_set<int> seen;
        for (const int& x : nums) {
            if (seen.count(x)) return x;
            seen.insert(x);
        }
        
        return -1;
    }
};
