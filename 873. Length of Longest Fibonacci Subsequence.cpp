class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) 
        {
            vector<int>nums;
            unordered_set<int> store;
            int ans = 0, n = arr.size();
            for(auto &val : arr) store.insert(val);
    
            for(int i = 0; i < n; i++)
            {
                nums.push_back(arr[i]);
                for(int j = i + 1; j < n; j++)
                {
                    nums.push_back(arr[j]);
                    while(store.count(nums[nums.size() - 1] + nums[nums.size() - 2])) 
                        nums.push_back(nums[nums.size() - 1] + nums[nums.size() - 2]);
    
                    ans = max(ans, int(nums.size()));
                    nums.resize(1);
                }
                nums.resize(0);
            }   
            return ans > 2 ? ans : 0;
        }
    };