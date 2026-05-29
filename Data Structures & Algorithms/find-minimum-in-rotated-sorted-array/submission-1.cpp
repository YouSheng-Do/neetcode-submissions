class Solution {
public:
    int findMin(vector<int> &nums) {
        //
        // right < left < mid => mid, right
        // mid < right < left => left, mid

        int left = 0, right = nums.size() - 1;
        int ans = INT_MAX;

        while (left <= right) {
            int mid = (right - left) / 2 + left;
            if (nums[mid] >= nums[left] && nums[mid] >= nums[right]) {
                left = mid + 1;
            }
            // else if (nums[mid] < nums[left] && nums[mid] < nums[right]) {
            //     right = mid - 1;
            // }
            else {
                right = mid - 1;
            }
            ans = min(ans, nums[mid]);
        }

        return ans;
    }
};
