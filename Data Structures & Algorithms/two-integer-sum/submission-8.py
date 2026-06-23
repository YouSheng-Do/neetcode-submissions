class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        val_to_index = dict()

        for i, x in enumerate(nums):
            diff = target - x
            if diff in val_to_index:
                return [val_to_index[diff], i]
            val_to_index[x] = i