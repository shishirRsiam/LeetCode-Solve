class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) 
    {
        long minPref = 0, maxPref = 0, pref = 0;
        for(auto &diff : differences)
        {
            pref += diff;
            minPref = min(minPref, pref);
            maxPref = max(maxPref, pref);
        }
        return max((upper - maxPref) - (lower - minPref) + 1, long(0));
    }
};