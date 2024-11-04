class Solution:
    def compressedString(self, word: str) -> str:
        count, ans, prev = 0, "", word[0]
        for ch in word:
            if ch != prev or count == 9:
                ans += str(count) + prev
                prev = ch
                count = 0
            count += 1

        if count:
            ans += str(count) + prev

        return ans