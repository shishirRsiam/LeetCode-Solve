class Solution(object):
    def stringHash(self, s, k):
        i = 0                # Initialize index `i` to 0
        ans = ''             # Initialize an empty string `ans` to store the final result
        n = len(s)           # Get the length of the input string `s`
        
        # Loop through the string `s` until the end
        while i < n:
            sum = 0          # Initialize the sum for the current group of `k` characters
            temp = k         # Initialize a temporary variable `temp` to `k`
            
            # Sum the values of `k` characters in the current group
            while temp:
                sum += ord(s[i]) - ord('a')  # Convert the character to its corresponding 0-based index (e.g., 'a' -> 0)
                i += 1                        # Move to the next character
                temp -= 1                     # Decrease `temp` by 1 until `k` characters are processed
            
            # Calculate the index of the resulting character in the alphabet
            idx = (sum % 26) % 26
            
            # Convert the index back to a character and append it to the result string `ans`
            ans += chr(idx + ord('a'))
        
        # Return the final hashed string
        return ans