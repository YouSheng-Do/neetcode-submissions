class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        buckets = [[] for _ in range(n + 1)]

        freq = Counter(nums)

        for x, f in freq.items():
            buckets[f].append(x)
        
        ans = []
        for i in range(n, -1, -1):
            for x in buckets[i]:
                ans.append(x)
            if len(ans) == k:
                return ans
        
        return ans