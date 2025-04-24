class Solution {
public:
    string longestWord(vector<string>& words) 
    {
        int n = words.size();
        sort(rbegin(words), rend(words));
        unordered_set<string> store(words.begin(), words.end());

        string ans;
        for(auto &s : words)
        {
            auto temp = s;
            bool isBuild = true;
            while(temp.size() > 1)
            {
                temp.pop_back();
                if(not store.count(temp))
                {
                    isBuild = false;
                    break;
                }
            }
            if(isBuild)
            {
                if(ans.size() == s.size())
                    ans = min(ans, s);
                else if(ans.size() < s.size())
                    ans = s;
                cout<<s<<endl;
            }
        }
        return ans;
    }
};