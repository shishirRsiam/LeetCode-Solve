class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n = s.size();
        vector<int>diff_arr(n + 5);
        for(auto shift : shifts)
        {
            int l = shift[0], r = shift[1], dir = shift[2];
            if(dir) diff_arr[l] += 1, diff_arr[r + 1] -= 1; 
            else diff_arr[l] -= 1, diff_arr[r + 1] += 1;
        }
        for(int i = 1; i < n; i++)
            diff_arr[i] += diff_arr[i - 1];
        
        string ans;
        for(int i = 0; i < n; i++)
            ans += (((s[i] - 'a' + diff_arr[i]) % 26 + 26) % 26) + 'a';
        return ans;
    }
};