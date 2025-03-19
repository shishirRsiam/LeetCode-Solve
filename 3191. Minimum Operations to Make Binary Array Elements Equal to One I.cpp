class Solution {
    public:
        int minOperations(vector<int>& nums) 
        {
            int ans = 0, n = nums.size(), flag = true;
            for(int i=0;i<n;i++)
            {
                if(not nums[i])
                {
                    int cnt = 0;
                    while (i+cnt < n and cnt < 3)
                    {
                        nums[i+cnt] = (nums[i+cnt] ? 0 : 1);
                        cnt++;
                    }
                    if(cnt == 3) ans++;
                    else flag = false;
                }
            }
            return flag ? ans : -1;
        }
    };