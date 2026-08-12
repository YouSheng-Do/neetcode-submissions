#include <cfloat>
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // two pass
        // find median of nums1 and binary search on nums2
        // select index i in nums1 and find insertion pos index j in nums2
        // duplicate number case
        // check i + j 
        // if m + n is odd; => check i + j == (m + n) / 2;
        // else => find (m + n) / 2 and (m + n) / 2 - 1, return the avg of two number
        // if we cannot find median from nums1, that means the median is in nums2
        // so the same thing oppositely

        if ((nums1.size() + nums2.size()) % 2) {
            double ans = findMedianForOdd(nums1, nums2);
            if (ans != -DBL_MAX) return ans;
            return findMedianForOdd(nums2, nums1);
        }
        else {
            double ans = findMedianForEven(nums1, nums2);
            if (ans != -DBL_MAX) return ans;
            return findMedianForEven(nums2, nums1);
        }

        return -DBL_MAX;
    }
    int binarySearch(int target, vector<int>& nums, bool equal) {
        // return the insertion pos
        int l = -1, r = nums.size();
        // -inf, nums[0], nums[1], .........nums[n - 1], inf
        // T,............................................F
        // find the last true, and return l + 1
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (target > nums[m]) l = m;
            else if (target == nums[m]) {
                if (equal) l = m;
                else r = m;
            }
            else r = m;
        }

        return l + 1;
    }
    double findMedianForOdd(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = nums1.size() - 1;
        int median = (nums1.size() + nums2.size()) / 2;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int new_index = m + binarySearch(nums1[m], nums2, true);
            if (new_index == median) return (double) nums1[m];
            if (new_index > median) r = m - 1;
            else l = m + 1;
        }

        return -DBL_MAX;
    }
    double findMedianForEven(vector<int>& nums1, vector<int>& nums2) {
        int l = 0, r = nums1.size() - 1;
        int median = (nums1.size() + nums2.size()) / 2;

        while (l <= r) {
            int m = l + (r - l) / 2;
            int pos = binarySearch(nums1[m], nums2, true);
            int new_index = m + pos;
            // cout << m << " " << pos << " " << new_index << endl;
            if (new_index == median - 1) {
                int nums1_next = (m < nums1.size() - 1) ? nums1[m + 1] : INT_MAX;
                int nums2_next = (pos < nums2.size()) ? nums2[pos] : INT_MAX;
                // cout << nums1_next << endl;
                // cout << nums2_next << endl;
                return (double) (nums1[m] + min(nums1_next, nums2_next)) / 2.0;
            }
            if (new_index == median) {
                int nums1_prev = (m > 0) ? nums1[m - 1] : INT_MIN;
                int nums2_prev = (pos > 0) ? nums2[pos - 1] : INT_MIN;
                return (double) (nums1[m] + max(nums1_prev, nums2_prev)) / 2.0;
            }
            if (new_index > median) r = m - 1;
            else l = m + 1;
        }

        return -DBL_MAX;
    }
};
