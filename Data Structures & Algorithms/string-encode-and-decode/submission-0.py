class Solution:
    def __init__(self):
        self.dictionary = {}
    def encode(self, strs: List[str]) -> str:
        encrypt = str()
        for i, s in enumerate(strs):
            self.dictionary[i] = s
            encrypt += str(i)
            encrypt += " "
        return encrypt

    def decode(self, s: str) -> List[str]:
        return [self.dictionary[int(i)] for i in s.split()]