// 06 Nov 2024
class Solution {
public:
    int getBit(int num)
    {
        bitset<10>bit(num);
        return bit.count();
    }
    bool canSortArray(vector<int>& nums) 
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(nums[j - 1] > nums[j])
                {
                    if(getBit(nums[j - 1]) == getBit(nums[j]))
                    {
                        swap(nums[j - 1], nums[j]);
                    }
                }
            }
        }
        return is_sorted(begin(nums), end(nums));
    }
};












// 11 Jun 2024
class Solution {
public:
    int bit(int val)
    {
        return bitset<10>(val).count();
    }
    bool canSortArray(vector<int>& nums) 
    {
        int n = nums.size(), flag = true;
        while(flag)
        {
            flag = false;
            for(int i=0;i<n-1;i++)
            {
                if(nums[i] > nums[i+1])
                {
                    if(bit(nums[i]) == bit(nums[i+1]))
                    {
                        swap(nums[i], nums[i+1]);
                        flag = true;
                    }
                }
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};