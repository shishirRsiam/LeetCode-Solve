class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        mp = defaultdict(int)
        mp2 = defaultdict(int)

        # Fill in the frequency map for s1
        for ch in s1:
            mp2[ch] += 1

        i, j = 0, 0
        k = len(s1)
        n = len(s2)

        while j < n:
            mp[s2[j]] += 1
            j += 1

            # When the window size is equal to s1's length
            if j - i == k:
                if mp == mp2:
                    return True
                
                # Sliding the window: remove character at i from the map
                mp[s2[i]] -= 1
                if mp[s2[i]] == 0:
                    del mp[s2[i]]
                i += 1

        return False