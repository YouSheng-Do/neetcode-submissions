class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # toy example
        # 3
        # [0, 1, 2]
        # {0 : 0, 1 : 1, }
        # 3 - 2 = 1 -> dict[1]=> 1 => return [1, 2]

        mapping = dict()  # val -> index

        for i, x in enumerate(nums):
            diff = target - x
            if mapping.get(diff) is not None:
                return [mapping[diff], i]
            mapping[x] = i
        
        return []
