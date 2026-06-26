class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)

        heap = []
        
        for x, f in freq.items():
            heapq.heappush(heap, (f, x))
            if (len(heap) > k):
                heapq.heappop(heap)

        ans = []
        while(len(heap)):
            top = heap[0][1]
            heapq.heappop(heap)
            ans.append(top)

        return ans