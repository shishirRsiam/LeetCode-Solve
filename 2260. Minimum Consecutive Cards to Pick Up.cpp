class Solution {
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int i = 0, j = 0, n = cards.size();
        while(j < n)
        {
            mp[cards[j]]++;
            while(mp[cards[j]] == 2)
            {
                ans = min(ans, j - i + 1);
                mp[cards[i++]]--;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};