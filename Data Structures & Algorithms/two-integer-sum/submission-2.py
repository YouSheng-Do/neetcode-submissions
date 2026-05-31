class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 3
        # [0, 1, 2]
        # {0 : 0, 1 : 1, }
        # 3 - 2 = 1 -> dict[1]=> 1 => return [1, 2]
        mapping = dict()
        for i, x in enumerate(nums):
            if mapping.get(target - x, -1) != -1:
                return [mapping[target - x], i]
            mapping[x] = i
        
        return []
