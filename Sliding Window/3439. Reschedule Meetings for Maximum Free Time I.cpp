class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) 
    {
        vector<int> freeTime;
        int n = startTime.size(), curTime = 0;
        for(int i = 0; i < n; i++)
        {
            freeTime.push_back(startTime[i] - curTime);
            curTime = endTime[i];
        }    
        freeTime.push_back(eventTime - curTime);

        n = freeTime.size();
        long ans = 0, i = 0, j = 0, sum = 0;
        while(j < n)
        {
            sum += freeTime[j++];
            if(j - i > k + 1) 
                sum -= freeTime[i++];
            ans = max(ans, sum);
        }
        return ans;
    }
};