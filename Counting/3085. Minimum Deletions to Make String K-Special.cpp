class Solution {
public:
    int minimumDeletions(string word, int k) 
    {
        vector<int> count(26);
        for(auto &ch : word)
            count[ch - 'a'] += 1;

        vector<int> arr;
        for(int i = 0; i < 26; i++)
            if(count[i]) arr.push_back(count[i]);
        
        int ans = word.size();
        for(auto &mid : arr)
        {
            int remove_count = 0;
            for(auto &val : arr)
            {
                if(val < mid) remove_count += val;
                else if(val <= mid + k) continue;
                else remove_count += (val - (mid + k));
            }
            ans = min(ans, remove_count);
        }
        return ans;
    }
};