class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        parentheses = {")" : "(", "}" : "{", "]" : "["}

        for c in s:
            if c not in parentheses:
                st.append(c)
            else:
                if not st or st[-1] != parentheses[c]:
                    return False
                st.pop()        

        return not st