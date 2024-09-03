class Solution(object): 
    def getValue(self, s):
        # Calculate the sum of the digits in the string 's'
        total = sum(int(ch) for ch in s)
        # Convert the sum to a string and return it
        return str(total)

    def getLucky(self, s, k):
        # Convert each character in 's' to its corresponding position in the alphabet
        # 'a' -> 1, 'b' -> 2, ..., 'z' -> 26
        converted = ''.join(str(ord(ch) - ord('a') + 1) for ch in s)
        
        # Perform the digit sum operation 'k' times
        for _ in range(k):
            # Update 'converted' by summing its digits using getValue
            converted = self.getValue(converted)
        
        # Convert the final string 'converted' back to an integer and return it
        return int(converted)