class Solution {
public:
    int maxOperations(string s) 
    {
        int oneCount = 0, ans = 0, n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0') ans += oneCount;
            while(i < n and s[i] == '0') i++;
            if(s[i] == '1') oneCount++;
        }
        return ans;
    }
};