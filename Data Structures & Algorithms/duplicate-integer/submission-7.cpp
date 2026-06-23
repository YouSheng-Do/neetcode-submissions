class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> unique;

        for (auto x : nums) {
            if (unique.count(x)) return true;
            unique.insert(x);
        }

        return false;
    }
};