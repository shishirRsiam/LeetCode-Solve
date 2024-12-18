class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> stact, ans(n);
        for(int i = 0; i < n; i++)
        {
            while(!stact.empty() and prices[stact.back()] >= prices[i])
            {
                ans[stact.back()] = prices[stact.back()] - prices[i];
                stact.pop_back();
            }
            stact.push_back(i);
        }

        for(auto &i : stact)
            ans[i] = prices[i];

        return ans;
    }
};