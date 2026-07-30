class Solution:
    def minimumPushes(self, word: str) -> int:
        count =  Counter(word)
        store = [(count[ch], ch) for ch in count]

        store.sort(reverse=True)

        ans, pos, cost = 0, 0, 1
        for count, ch in store:
            ans += (count * cost)

            pos += 1
            cost += bool(pos % 8 == 0)
            
        return ans