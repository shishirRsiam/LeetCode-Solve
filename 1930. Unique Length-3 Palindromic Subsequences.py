class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n =  len(s)
        pref, suf = {}, {}

        count = defaultdict(int)
        for i in range(n):
            pref[i] = dict(count)
            count[s[i]] += 1
            
        count = defaultdict(int)
        i = n - 1
        while i >= 0:
            suf[i] = dict(count)
            count[s[i]] += 1
            i -= 1
        
        store = set()
        for i in range(n):
            pf, sf = pref[i], suf[i]
            for ch in ascii_lowercase:
                if ch in pf and pf[ch] and ch in sf and sf[ch]:
                    store.add(f"{ch}{s[i]}{ch}")
        return len(store)