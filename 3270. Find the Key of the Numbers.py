class Solution(object):
    def generateKey(self, num1, num2, num3):
        # Convert each number to a string and store them in a list
        vec = [str(num1), str(num2), str(num3)]
        
        # Ensure each string has exactly 4 digits by padding with leading zeros if necessary
        for i in range(3):
            vec[i] = vec[i].zfill(4)  # zfill pads the string with leading zeros to make it 4 digits long
        
        ans = ""  # Initialize an empty string to store the final result
        
        # Iterate over each digit position (0 to 3) in the strings
        for i in range(4):
            # Find the minimum character at the current position across all three strings
            ch = min(vec[0][i], vec[1][i], vec[2][i])
            # Append the minimum character to the result string
            ans += ch
        
        # Convert the resulting string back to an integer and return it
        return int(ans)