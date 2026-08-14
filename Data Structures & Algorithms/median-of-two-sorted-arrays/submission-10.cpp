class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // think about how to find the median of a sorted array
        // we have to find the partition that make the number of left half is (n + 1) / 2
        // [1, 2, 3,| 4, 5], half = 3 
        // => median = 3
        // [1, 2, 3,| 4, 5, 6], half = 6 
        // => median = (3 + 4) / 2 = 3.5
        
        // Median of two sorted array 
        // half = (m + n + 1) / 2
        // if we cut nums1 on i?
        // nums1 = [............l1|r1..........], partition on i
        // nums2 = [............l2|r2..........], partition on j
        // j = half - i
        // how to check that this is right partition
        // l1 <= r1 and l2 <= r2, because they are sorted
        // if (l1 <= r2 && l2 <= r1) => right parition
        // => if (m + n) is odd => return max(l1, l2)
        // => if (m + n) is even => return (max(l1, l2) + min(r1, r2)) / 2.0
        // binary search
        // l = 0, r = n;
        // while (l <= r)
        // if (l1 > r2) => parition too much on nums1
        // r = mid - 1;
        // if (l2 > r1) => parition too less on nums1
        // l = mid + 1;
        // l1 > r2 && l2 && r1 => impossible
        // we known r2 >= l2 and r1 >= l1
        // l1 > r2 > l2 > r1 => conflict
        // return INT_MIN;

        // search on the array with smaller length
        // O(log min(m, n))

        // O(1) time
        // because they just exchange their pointer rather than copy
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        const int m = nums1.size(), n = nums2.size();
        // m <= n

        int half = (m + n + 1) / 2;

        int l = 0, r = m;
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = half - i;
            // cout << i << " " << j << endl;
            int l1 = i == 0 ? INT_MIN : nums1[i - 1];
            int r1 = i == m ? INT_MAX : nums1[i];
            int l2 = j == 0 ? INT_MIN : nums2[j - 1];
            int r2 = j == n ? INT_MAX : nums2[j];
            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2) return (double) max(l1, l2);
                return (double) (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }

        return INT_MIN;
    }
};
