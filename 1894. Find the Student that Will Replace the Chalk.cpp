class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        long allSum = 0;
        
        // Calculate the total sum of all elements in the chalk array
        for(auto val : chalk)
            allSum += val;
        
        // Calculate the remainder of k when divided by allSum
        // This determines how much chalk remains after several full cycles
        long mod = k % allSum, n = chalk.size();
        
        // Iterate through the chalk array
        for(int i = 0; i < n; i++)
        {
            // If the current student's chalk usage is more than the remaining chalk, return their index
            if(chalk[i] > mod) return i;
            
            // Otherwise, subtract the current student's chalk usage from the remaining chalk
            mod -= chalk[i];
        }
        
        // This line should never be reached since the problem guarantees a solution.
        return mod;
    }
};