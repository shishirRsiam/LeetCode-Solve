class Solution {
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        set<int> available_days;
        for (int d = 1; d <= 100000; d++) 
            available_days.insert(d);

        int attend = 0;
        for (auto &event : events)
        {
            auto it = available_days.lower_bound(event[0]);
            if (it != available_days.end() && *it <= event[1]) 
            {
                attend++;
                available_days.erase(it);
            }
        }
        return attend;
    }
};