class Solution {
public:
    string longestWord(vector<string>& words) 
    {
        int n = words.size();
        sort(rbegin(words), rend(words));
        unordered_set<string> store(words.begin(), words.end());


        string ans;
        unordered_set<string> possibleToBuild;
        for(auto &s : words)
        {
            if(possibleToBuild.count(s)) continue;

            auto temp = s;
            bool isBuild = true;
            while(temp.size() > 1)
            {
                temp.pop_back();
                if(possibleToBuild.count(temp)) break;
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

                temp = s;
                while(temp.size() > 1)
                {
                    temp.pop_back();
                    possibleToBuild.insert(temp);
                }
            }
        }
        return ans;
    }
};