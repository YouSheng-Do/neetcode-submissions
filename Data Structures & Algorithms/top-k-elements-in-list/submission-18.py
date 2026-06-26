class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)

        heap = []
        
        for x, f in freq.items():
            heapq.heappush(heap, (f, x))
            if len(heap) > k:
                heapq.heappop(heap)

        return [x for f, x in heap]