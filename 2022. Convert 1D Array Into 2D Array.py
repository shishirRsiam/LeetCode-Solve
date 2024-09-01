class Solution(object):
    def construct2DArray(self, original, m, n):
        # Check if the total elements match m * n
        if n * m != len(original):
            return []
        
        ans = []
        temp = []
        cnt = 0
        
        for val in original:
            temp.append(val)  # Add the current element to the temp row
            cnt += 1
            
            if cnt == n:  # If temp has enough elements for one row
                ans.append(temp)  # Append the row to the 2D array
                temp = []  # Reset temp for the next row
                cnt = 0  # Reset the counter

        return ans