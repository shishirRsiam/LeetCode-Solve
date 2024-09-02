var chalkReplacer = function(chalk, k) 
{
    let allSum = 0;
    
    // Calculate the total sum of all elements in the chalk array
    for(let val of chalk) 
        allSum += val;
    
    // Calculate the remainder of k when divided by allSum
    // This determines how much chalk remains after several full cycles
    let mod = k % allSum;
    
    // Get the number of students
    let n = chalk.length;
    
    // Iterate through the chalk array
    for(let i = 0; i < n; i++)
    {
        // If the current student's chalk usage is more than the remaining chalk, return their index
        if(chalk[i] > mod) 
            return i;
        
        // Otherwise, subtract the current student's chalk usage from the remaining chalk
        mod -= chalk[i];
    }
    
    // This line should never be reached since the problem guarantees a solution.
    return mod;
};