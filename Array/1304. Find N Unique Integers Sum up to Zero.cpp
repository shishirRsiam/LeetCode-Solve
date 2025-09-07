class Solution {
public:
    vector<int> sumZero(int n) 
    {
        int cur_num = 1;
        vector<int> ans;
        while(n > 1)
        {
            n -= 2, cur_num += 1;
            ans.push_back(cur_num);
            ans.push_back(-cur_num);
        }
        if(n) ans.push_back(0); 
        return ans;
    }
};