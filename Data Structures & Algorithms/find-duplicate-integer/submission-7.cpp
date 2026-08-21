class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // binary search
        // sort
        // check nums[i] with index i
        // nums[i] >= i + 1 => correct
        // find the first incorrect value
        // set l = -1, r = nums.size() - 1;
        // make nums[l] is always correct and nums[r] is always incorrect
        // while (l + 1 < r) 
        // return r
        //   [1,1,2,3]

        // T,       F
        // if nums[i] >= i + 1 => lack some number < nums[i] => dupicate number index > i => l = i
        // if nums[i] < i + 1 => too many number < nums[i] => duplicate number index < i => r = i
        sort(nums.begin(), nums.end());
        int l = -1, r = nums.size();

        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= m + 1) {
                l = m;
            }
            else {
                r = m;
            }
        }

        return r;
    }
};
