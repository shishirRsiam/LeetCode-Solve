class Solution:
    def validateCoupons(self, code: List[str], businessLine: List[str], isActive: List[bool]) -> List[str]:
        def is_valid_code(s):
            return bool(fullmatch(r'[A-Za-z0-9_]+', s))

        store = []
        n = len(code)
        accept_Line = set(["electronics", "grocery", "pharmacy", "restaurant"])
        for i in range(n):
            if not isActive[i] or not is_valid_code(code[i]):
                continue
            elif businessLine[i] not in accept_Line:
                continue
            store.append([businessLine[i], code[i]])
        
        store.sort()
        return [val[1] for val in store]