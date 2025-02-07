class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) 
        {
            int n = queries.size();
            unordered_map<int, int> color, ball;
    
            vector<int> ans(n);
            for(int i = 0; i < n; i++)
            {
                auto x = queries[i][0], y = queries[i][1];
    
                if(ball[x] and not --color[ball[x]]) 
                    color.erase(ball[x]);
                
                ball[x] = y;
                color[y] += 1;
                ans[i] = color.size();
            }
    
            return ans;
        }
    };