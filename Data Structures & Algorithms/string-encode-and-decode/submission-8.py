class Solution:

    def encode(self, strs: List[str]) -> str:
        if not strs:
            return ""

        s = ""

        for string in strs:
            s += str(len(string))
            s += '#'
            s += string
        
        return s
        
    def decode(self, s: str) -> List[str]:
        if not s:
            return []

        i = 0

        strs = []
        while (i < len(s)):
            j = i
            while s[j] != '#':
                j += 1
            
            sz = int(s[i:j])

            j += 1

            string = s[j:j + sz]
            
            strs.append(string)
            i = j + sz
        
        return strs