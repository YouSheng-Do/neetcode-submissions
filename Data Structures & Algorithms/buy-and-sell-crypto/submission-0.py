class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minimum = prices[0]
        diff = 0

        for p in prices:
            if p < minimum:
                minimum = p
            if p > minimum:
                diff = max(diff, p - minimum)
        
        return diff