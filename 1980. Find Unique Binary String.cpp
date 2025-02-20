class Solution {
    public:
        set<string>st;
        string ans, path;
        void backtrack(int n)
        {
            if(!ans.empty()) return;
            if(n == 0)
            {
                if(not (st.count(path)))
                    ans = path;
                return;
            }
    
            path += '0';
            backtrack(n-1);
            path.pop_back();
    
            path += '1';
            backtrack(n-1);
            path.pop_back();
        }
        string findDifferentBinaryString(vector<string>& nums) 
        {
            for(auto val:nums)
                st.insert(val);
            backtrack(nums[0].size());
            return ans;
        }
    };