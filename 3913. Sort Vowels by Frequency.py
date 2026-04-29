class Solution:
    def sortVowels(self, s: str) -> str:
        n = len(s)

        trac_index = {}
        count = Counter(s)
        for i in range(n):
            if s[i] in 'aeiuo' and s[i] not in trac_index:
                trac_index[s[i]] = i
        
        sorting_array = [(count[ch], trac_index[ch], ch) for ch in count if ch in 'aeiou']
        sorting_array.sort(key=lambda x: (-x[0], x[1]))
        sorted_vowels = ''.join(ch * cnt for cnt, idx, ch in sorting_array)

        i = 0
        ans = []
        for ch in s:
            if ch in 'aeiou':
                ans.append(sorted_vowels[i])
                i += 1
            else: ans.append(ch)
        return ''.join(ans)