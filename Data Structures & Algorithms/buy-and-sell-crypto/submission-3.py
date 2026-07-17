class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimum = prices[0]
        diff = 0

        for p in prices:
            minimum = min(p, minimum)
            diff = max(diff, p - minimum)
        
        return diff