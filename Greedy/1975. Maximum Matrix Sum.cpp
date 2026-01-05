class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long sum = 0;
        int maxValue = INT_MAX, neg = 0;
        for(auto vec:matrix)
        {
            for(auto val:vec)
            {
                sum += abs(val);
                if(val < 0) neg += 1;
                maxValue = min(maxValue, abs(val));
            }
        }

        if(neg % 2) sum -= maxValue * 2;

        return sum;
    }
};