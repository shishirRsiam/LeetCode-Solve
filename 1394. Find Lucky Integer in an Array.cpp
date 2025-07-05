class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> count;
        for(auto &val : arr)
            count[val] += 1;

        int ans = -1;
        for(auto [val, cnt] : count)
            if(val == cnt) 
                ans = max(ans, val);
        return ans; 
    }
};



class Solution {
public:
    int findLucky(vector<int>& a) 
    {
        vector<int>ans(501,0); 
        for(int i = 0; i < a.size(); i++)
            ans[a[i]]++;

        stack<int> ret;
        for(int i = 1; i < 500; i++)
        {
            if(ans[i] == i)
                ret.push(i);
        }

        if(ret.empty())
            return -1;
        return ret.top();
    }
};