class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) 
    {
        int m = languages.size();
        vector<unordered_set<int>> lanKnow(505);
        for(int i = 0; i < m; i++) 
            for(int lang : languages[i])
                lanKnow[i + 1].insert(lang);

        unordered_set<int> usersNeedTeach;
        vector<pair<int, int>> cannotTalk;
        for(auto &f : friendships) 
        {
            bool canTalk = false;
            int u1 = f[0], u2 = f[1];
            for(int lang : lanKnow[u1])
            {
                if(lanKnow[u2].count(lang)) 
                {
                    canTalk = true;
                    break;
                }
            }

            if(not canTalk) 
            {
                usersNeedTeach.insert(u1);
                usersNeedTeach.insert(u2);
                cannotTalk.push_back({u1, u2});
            }
        }

        int ans = INT_MAX;
        for(int lang = 1; lang <= n; lang++) 
        {
            int count = 0;
            for(int user : usersNeedTeach) 
                count += not lanKnow[user].count(lang);
            ans = min(ans, count);
        }
        return ans;
    }
};