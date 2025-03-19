var minOperations = function(nums) 
{
    let ans = 0, n = nums.length;
    for(let i = 0; i < n; i++)
    {
        if(!nums[i] && i + 2 < n)
        {
            ans += 1;
            nums[i] = !nums[i];
            nums[i + 1] = !nums[i + 1];
            nums[i + 2] = !nums[i + 2];
        }
    }

    if(nums[n - 1] && nums[n - 2] && nums[n - 3]) return ans;
    return -1;
};