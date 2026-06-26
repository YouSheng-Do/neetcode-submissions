class Solution:

    def encode(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        
        encrypt = str()
        for s in strs:
            encrypt += str(len(s))
            encrypt += ','
        
        encrypt += '#'
        for s in strs:
            encrypt += s
        return encrypt

    def decode(self, s: str) -> List[str]:
        if s == "":
            return []
        pos = s.find('#')

        length = s[:pos]
        strs = s[pos + 1:]

        ans = []
        i = 0
        for l in length.split(','):
            if l == '':
                continue
            ans.append(strs[i:i + int(l)])
            i += int(l)
        
        return ans