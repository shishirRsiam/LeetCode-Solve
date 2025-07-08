class Solution {
public:
    auto findNextEvent(int cur_end_time, vector<vector<int>>& events)
    {
        int index = events.size();
        int left = 0, right = index - 1, mid;
        while(left <= right)
        {
            mid = left + (right - left) / 2;
            if(cur_end_time < events[mid][0])
                index = mid, right = mid - 1;
            else left = mid + 1;
        }
        return index;
    }
    vector<vector<int>> memo;
    auto solve(int cur, int k, vector<vector<int>>& events)
    {
        if(not k or cur == events.size()) return 0;
        if(memo[cur][k] != -1) return memo[cur][k];

        int next_index = findNextEvent(events[cur][1], events);

        auto skip = solve(cur + 1, k, events);
        auto take = events[cur][2] + solve(next_index, k - 1, events);

        return memo[cur][k] = max(take, skip);
    }
    int maxValue(vector<vector<int>>& events, int k) 
    {
        sort(begin(events), end(events));
        memo.resize(events.size() + 10, vector<int>(k + 10, -1));
        return solve(0, k, events);
    }
};