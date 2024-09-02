class Solution(object):
    def chalkReplacer(self, chalk, k):
        allSum = 0
        
        # Calculate the total sum of all elements in the chalk array
        for val in chalk:
            allSum += val
        
        # Calculate the remainder of k when divided by allSum
        # This determines how much chalk remains after several full cycles
        mod = k % allSum
        
        # Get the number of students
        n = len(chalk)
        
        # Iterate through the chalk array
        for i in range(n):
            # If the current student's chalk usage is more than the remaining chalk, return their index
            if chalk[i] > mod:
                return i
            
            # Otherwise, subtract the current student's chalk usage from the remaining chalk
            mod -= chalk[i]
        
        # This line should never be reached since the problem guarantees a solution.
        return mod