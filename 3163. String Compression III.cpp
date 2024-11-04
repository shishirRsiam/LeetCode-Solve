class Solution {
public:
    string compressedString(string word) 
    {
        string ans;

        int count = 0;
        char prev = word[0];
        for(auto ch : word)
        {
            if(prev != ch or count == 9)
            {
                ans += to_string(count);
                ans += prev;
                prev = ch;
                count = 0;
            }
            count += 1;
        }
        if(count)
        {
            ans += to_string(count);
            ans += prev;
        }
        return ans;
    }
};