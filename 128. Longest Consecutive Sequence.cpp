class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans = 0, cur_num, cur_stack;
        unordered_set<int> numbers(begin(nums), end(nums));
        for(auto num:numbers)
        {
            if(numbers.find(num - 1) == numbers.end())
            {
                cur_num = num;
                cur_stack = 1;
                while(numbers.count(cur_num + 1))
                {
                    cur_num += 1;
                    cur_stack += 1;
                }
                ans = max(ans, cur_stack);
            }
        }
        return ans;
    }
};