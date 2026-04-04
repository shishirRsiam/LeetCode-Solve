class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if not encodedText:
            return ""

        rows_store = []
        n = len(encodedText)
        col_size = n // rows
        for i in range(0, n, col_size):
            rows_store.append(encodedText[i:i+col_size])
            i += col_size

        store = defaultdict(list)
        for i in range(rows):
            for j in range(col_size):
                store[j-i].append(rows_store[i][j])
        
        ans = []
        for i in range(col_size):
            ans.append(''.join(store[i]))
        for i in range(1, rows):
            ans.append(''.join(store[-i]))
        
        ans = ''.join(''.join(ans))
        n = len(ans)
        for i in range(n - 1, -1, -1):
            if ans[i] in ascii_lowercase:
                return ans[:i + 1]
        return "ok" # Not Reched!