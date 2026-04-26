class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for (int& x : nums) {
            if (uset.count(x)) return true;
            uset.insert(x);
        }

        return false;
    }
};