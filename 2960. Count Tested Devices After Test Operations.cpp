class Solution {
    public:
        int countTestedDevices(vector<int>& batteryPercentages) 
        {
            int ans = 0;
            for(auto val : batteryPercentages)
                ans += ans < val;
            return ans;    
        }
    };