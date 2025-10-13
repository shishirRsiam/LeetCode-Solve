class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        store = []
        for word in words:
            sorted_word = sorted(word)
            store.append((word, sorted_word))

        i, j = 0, 1
        while j < len(words):
            word_i, sorted_word_i = store[i]
            word_j, sorted_word_j = store[j]
            if sorted_word_i == sorted_word_j:
                store[j] = []
            else: i = j
            j += 1
        
        ans = []
        for pair in store:
            if not pair:
                continue
            ans.append(pair[0])
        return ans