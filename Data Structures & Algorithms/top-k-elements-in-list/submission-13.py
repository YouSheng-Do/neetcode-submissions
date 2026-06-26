class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        print(Counter(nums).most_common(k))
        return [k for k, v in Counter(nums).most_common(k)]