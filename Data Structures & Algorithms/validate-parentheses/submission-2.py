class Solution:
    def isValid(self, s: str) -> bool:
        st = []
        for c in s:
            if c == '(' or c == '[' or c == '{':
                st.append(c)
            else:
                if not st:
                    return False
                top = st[-1]
                if c == ')' and top != '(':
                    return False
                if c == ']' and top != '[':
                    return False
                if c == '}' and top != '{':
                    return False
                st.pop()        

        return not st