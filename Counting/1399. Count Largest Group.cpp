class Solution {
public:
    int countLargestGroup(int n) 
    {
        int max_count = 0;
        unordered_map<int, int>count;
        for(int i = 1; i <= n; i++)
        {
            int sum = 0;
            string s = to_string(i);
            for(char ch : s) 
                sum += ch - '0';
            count[sum] += 1;

            max_count = max(max_count, count[sum]);
        }

        int ans = 0;
        for(auto [val, cnt] : count) 
            ans += cnt == max_count;
        return ans;
    }
};