class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) 
    {
        long sum1 = 0, sum2 = 0, count1 = 0, count2 = 0;
        for(auto &val : nums1)
            sum1 += val, count1 += val == 0;
        for(auto &val : nums2)
            sum2 += val, count2 += val == 0;

        if (not count1 and not count2)
            return sum1 == sum2 ? sum1 : -1;

        if(count1 and count2)
            return max(sum1 + count1, sum2 + count2);
        else if(count1 and sum1 + count1 <= sum2)
            return sum2;
        else if(count2 and sum2 + count2 <= sum1)
            return sum1;
        return -1;
    }
};