class Solution {
public:
    string countAndSay(int n) 
    {
        if(n==1) return "1";

        string ans, say = countAndSay(n-1);

        int cnt = 1, nn = say.size();
        char ch = say[0];
        for(int i=1;i<nn;i++)
        {
            if(say[i]==ch) cnt++;
            else 
            {
                ans += to_string(cnt);
                ans += ch;
                cnt = 1;
                ch = say[i];
            }
        }
        ans += to_string(cnt);
        ans += ch;
        return ans;
    }
};