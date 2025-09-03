class cmp {
    public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
};

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) 
    {
        int ans = 0, n = points.size();
        sort(points.begin(), points.end(), cmp());
        for(int i = 0; i < n; i++)
        {
            int best = -1e9 * 2;
            auto ax = points[i][0], ay = points[i][1];
            for(int j = i + 1; j < n; j++)
            {
                auto bx = points[j][0], by = points[j][1];

                if(by > ay) continue;
                if(by > best) ans += 1, best = by;
            }
        }    
        return ans;
    }
};