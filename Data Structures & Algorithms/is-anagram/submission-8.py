class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        diff = defaultdict(int)

        if len(s) != len(t):
            return False
        
        for ch1, ch2 in zip(s, t):
            diff[ch1] += 1
            diff[ch2] -= 1
        
        return all(x == 0 for x in diff.values())