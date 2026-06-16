class Solution:
    def processStr(self, s: str) -> str:
        store = []
        for ch in s:
            if ch == '*':
                if store: store.pop()
            elif ch == '#':
                store += store
            elif ch == '%':
                store = store[::-1]
            else:
                store.append(ch)
        return ''.join(store)