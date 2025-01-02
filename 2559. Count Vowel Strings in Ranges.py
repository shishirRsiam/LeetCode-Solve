
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        def is_vowel(char):
            return char.lower() in "aeiou"
        pref = [0]
        for word in words:
            pref.append(pref[-1] + (is_vowel(word[0]) and is_vowel(word[-1])))

        ans = []
        for left, right in queries:
            ans.append(pref[right + 1] - pref[left])
        return ans