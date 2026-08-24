class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(n)
        // avg : O(n), worst : O(n^2)
        // quickselect
        // select a pivot every term and partition nums into two part(smaller part, larger part)
        // smaller part contains number < pivot
        // larger part contains number >= pivot
        // so we can know the pivot is the i-th largest number in nums
        // check i (pivot index) with k and choose which part contain the ans
        // binary search
        // the time complexity for quick sort is O(nlogn)
        // T(n) = T(n/2) + T(n/2) + O(n) => O(nlogn)
        // beacause we always choose one part that contain ans
        // T(n) = T(n/2) + O(n) = T(n/4) + O(n/2) + O(n)
        // => O(n) + O(n/2) + O(n/4) + ..... O(2) + O(1)
        // => O(n) + O(n - 1) (formula)
        // => O(2 * n)
        // avg time is O(n), worst time is O(n^2) when the pivot partition nums into uneven two parts
        return quickselect(nums, k);
    }
private:
    int quickselect(vector<int>& nums, int k) {
        // binary search + quick select
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int pivot_index = partition(nums, l, r);
            if (pivot_index == k - 1) return nums[pivot_index];
            if (pivot_index < k - 1) l = pivot_index + 1;
            else r = pivot_index -1;
        }

        return -1;
    }
    int partition(vector<int>& nums, int l, int r) {
        // return the pivot index
        int pivot = nums[r];
        int larger_or_eqial_index = l;
        for (int i = l; i < r; ++i) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[larger_or_eqial_index]);
                larger_or_eqial_index++;
            }
        }
        swap(nums[larger_or_eqial_index], nums[r]);
        return larger_or_eqial_index;
    }
};
