class Solution {
public:
    bool checkIsSorted(vector<int> ratings)
    {
        int n = ratings.size();
        bool flag1 = true, flag2 = true;
        for(int i = 0; i < n - 1; i++)
        {
            if(ratings[i] >= ratings[i + 1])
            {
                flag1 = false;
                break;
            }
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(ratings[i] <= ratings[i + 1])
            {
                flag2 = false;
                break;
            }
        }
        return flag1 or flag2;
    }
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        
        if(checkIsSorted(ratings))
            return long(n * (n + 1)) / 2;

        bool flag = true;
        vector<int> storeCandy(n, 1);
        while(flag)
        {
            flag = false;
            for(int i = 1; i < n - 1; i++)
            {
                if(storeCandy[i] <= storeCandy[i + 1] and ratings[i] > ratings[i + 1])
                    storeCandy[i] += 1, flag = true;
                else if(storeCandy[i] <= storeCandy[i - 1] and ratings[i] > ratings[i - 1])
                    storeCandy[i] += 1, flag = true;
            }
            if(n > 1 and ratings[0] > ratings[1])
                storeCandy[0] = storeCandy[1] + 1;
            if(n > 1 and ratings[n - 1] > ratings[n - 2])
                storeCandy[n - 1] = storeCandy[n - 2] + 1;
        }

        int ans = 0;
        for(auto candy : storeCandy)
            ans += candy;
        return ans;    
    }
};