class Solution {
public:
    bool is_prime(int num)
    {
        for(int i = 2; i <= sqrt(num); i++)
            if(not (num % i)) return false;
        return true;
    }
    bool primeSubOperation(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int bound = nums[i];
            if(i) bound -= nums[i - 1];

            for(int j = bound - 1; j >= 2; j--)
            {
                if(is_prime(j))
                {
                    nums[i] -= j;
                    break;
                }
            }
        }

        for(int i = 1; i < n; i++)
            if(nums[i] <= nums[i - 1]) return false;
        return true;
    }
};