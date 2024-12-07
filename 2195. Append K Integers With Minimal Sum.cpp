class Solution {
public:
    long ans = 0, num = 0;
    void ProccessK(long num1, long num2, int &k, int numbers, vector<int>&nums, int i)
    {
        if(numbers <= k) ans += num2 - num1;
        else 
        {
            nums[i + 1] = k + 1;
            if(i >= 0 ) nums[i + 1] += nums[i];

            num2 = (nums[i + 1] * long(nums[i + 1] - 1)) / 2;
            ans += num2 - num1;
        }
        k -= (numbers - 1);
    }
    long long minimalKSum(vector<int>& nums, int k) 
    {
        sort(begin(nums), end(nums));

        int n = nums.size(), numbers;
        long num1 = 0;
        long num2 = (nums[0] * long(nums[0] - 1)) / 2;
        if(nums[0] > 1)
        {
            numbers = nums[0];
            ProccessK(num1, num2, k, numbers, nums, -1);
        }

        for(int i = 0; i < n - 1; i++)
        {
            if(k <= 0) break;
            if(nums[i + 1] - nums[i] <= 1) continue;
            numbers = nums[i + 1] - nums[i];
            num1 = (nums[i] * long(nums[i] + 1)) / 2;
            num2 = (nums[i + 1] * long(nums[i + 1] - 1)) / 2;

            ProccessK(num1, num2, k, numbers, nums, i);
        }

        if(k > 0)
        {
            int i = n;
            nums.push_back(nums.back());
            nums.push_back(nums.back() + k + 1);

            numbers = nums[i + 1] - nums[i];
            num1 = (nums[i] * long(nums[i] + 1)) / 2;
            num2 = (nums[i + 1] * long(nums[i + 1] - 1)) / 2;
            ProccessK(num1, num2, k, numbers, nums, i);
        }
        
        return ans;
    }
};