var minimumRecolors = function(blocks, k) 
{
    let n = blocks.length;
    let i = 0, j = 0, ans = k, count = 0;    
    while(j < n)
    {
        count += blocks[j++] == 'W';
        if(j - i == k) 
        {
            ans = Math.min(ans, count);
            count -= blocks[i++] == 'W';
        }
    }
    return ans;
};