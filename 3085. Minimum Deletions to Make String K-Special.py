class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        count = Counter(word)
        
        arr = []
        for ch in ascii_lowercase:
            arr.append(count[ch])

        ans = 1e9
        for mid in arr:
            remove_count = 0
            for val in arr:
                if val < mid: 
                    remove_count += val
                elif val <= mid + k:
                    continue
                else:
                    remove_count += (val - (mid + k))
            ans = min(ans, remove_count)
        return ans