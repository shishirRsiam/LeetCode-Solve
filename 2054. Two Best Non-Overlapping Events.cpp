class Solution {
public:
    int n;
    vector<vector<int>> memo;
    int binarySearch(vector<vector<int>>& events, int endTime) 
    {
        int l = 0, r = n - 1, ans = n, mid; 
        while (l <= r) 
        {
            mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }

    int Recursion(vector<vector<int>>& events, int i, int count) 
    {
        if (count == 2 or i >= n) return 0;
        if(memo[i][count] != -1) return memo[i][count];

        int nextValidEventIndex = binarySearch(events, events[i][1]);

        int take = events[i][2] + Recursion(events, nextValidEventIndex, count + 1);
        int not_take = Recursion(events, i + 1, count);

        return memo[i][count] = max(take, not_take);
    }

    int maxTwoEvents(vector<vector<int>>& events) 
    {
        n = events.size();
        memo.resize(n, vector<int>(3, -1));

        sort(events.begin(), events.end());
        return Recursion(events, 0, 0);
    }
};