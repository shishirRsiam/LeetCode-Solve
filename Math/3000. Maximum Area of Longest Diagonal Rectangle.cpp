class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) 
    {
        auto ans = 0.0, maxSqrt = 0.0;
        sort(begin(dimensions), end(dimensions));
        for(auto dimension : dimensions)
        {
            auto val1 = dimension[0], val2 = dimension[1];
            auto curSqrt = sqrt((val1 * val1) + (val2 * val2));
            if (maxSqrt <= curSqrt)
            {
                maxSqrt = curSqrt;
                ans = val1 * val2;
            }
        }
        return ans;
    }
};