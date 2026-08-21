class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we want not modify the nuns and O(1) space
        // treat the array like a linked list
        // each index points to the next index given by its value
        // because one number is duplicated, two indices will point to same value, creating a cycle
        // use fast and slow pointer to detect cycle
        // fast = 0, slow = 0;
        // do {
        //   fast = nums[nums[fast]];
        //   slow = nums[slow];
        // } while (slow != fast)

        // find a cycle
        // how to find the duplicate number
        // think about how many steps the the two pointers go
        // start ------> cycle entrance ------> meeting point
        //          a                      b
        // slow : a + b steps
        // fast : 2 * (a + b) steps
        // a + b = k * L (length of the cycle)
        // a ≡ -b ≡ L - b (mod L)
        // from meeting point, if we go a steps we can get to the entrance of cycle
        // from start, if we go a steps we can get to the entrance of cycle too
        // so we can set a pointer to the start and the slow pointer keep going.
        // when they meet, it's the entrance of cycle(duplicate number)

        // [1, 3, 4, 2, 2]
        // fast : 4
        // slow : 4

        int fast = 0, slow = 0;

        // find meeting point
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (slow != fast);


        int slow2 = 0;
        // entrance of cycle
        while (slow != slow2) {
            slow = nums[slow];
            slow2 = nums[slow2];
        }

        return slow;
    }
};
