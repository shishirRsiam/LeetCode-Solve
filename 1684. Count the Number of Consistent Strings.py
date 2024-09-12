class Solution(object):
    def countConsistentStrings(self, allowed, words):
        ans = 0
        allowed = set(allowed)  # Convert allowed string to set once
        
        for word in words:  # Iterate through the original list of words
            word = set(word)  # Convert each word to a set of characters
            flag = True
            for ch in word:
                if ch not in allowed:  # Check if any character is not in allowed
                    flag = False
                    break
            ans += flag  # If flag is True, increment the count
        
        return ans