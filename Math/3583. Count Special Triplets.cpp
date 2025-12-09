class Solution {
public:
    int specialTriplets(vector<int>& nums) 
    {
        unordered_map<int, int> leftCount, rightCount;
        for(auto &val : nums) rightCount[val] += 1;
        leftCount[nums[0]] += 1;
        rightCount[nums[0]] -= 1;

        long val, left_count, right_count;
        long ans = 0, mod = 1e9 + 7, n = nums.size();
        for(int i = 1; i < n - 1; i++)
        {
            val = nums[i];

            rightCount[val] -= 1;

            left_count = leftCount[val + val];
            right_count = rightCount[val + val];

            leftCount[val] += 1;

            ans = (ans + (left_count * right_count)) % mod;
        }
            
        return ans % mod;    
    }
};