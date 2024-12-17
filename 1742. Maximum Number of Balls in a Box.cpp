class Solution {
public:
    int countBalls(int lowLimit, int highLimit) 
    {
        int ans = 0, sum;
        unordered_map<int, int> count;
        for(int number = lowLimit; number <= highLimit; number++)
        {
            sum = 0;
            string s = to_string(number);
            for(auto ch : s)
                sum += ch - '0';
                
            count[sum] += 1;
            ans = max(ans, count[sum]);
        }
        return ans;    
    }
};