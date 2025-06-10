class Solution {
public:
    int maxDifference(string s) 
    {
        vector<int> count(26);
        for(auto &ch : s)
            count[ch - 'a'] += 1;

        int max_odd = 0, min_even = INT_MAX;
        for(int i = 0; i < 26; i++)
        {
            if(count[i] and count[i] % 2)
                max_odd = max(max_odd, count[i]);
            else if(count[i])
                min_even = min(min_even, count[i]);
        }

        return (max_odd - min_even);  
    }
};