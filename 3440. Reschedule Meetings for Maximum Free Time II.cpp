class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) 
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
        vector<int> leftMaxFree(n), rightMaxFree(n);
        for(int i = n - 1; i; i--)
            rightMaxFree[i - 1] = max(rightMaxFree[i], freeTime[i]);
        for(int i = 0; i < n - 1; i++)
            leftMaxFree[i + 1] = max(leftMaxFree[i], freeTime[i]);

        int ans = 0, currEventTime, maxConsicutiveTime;
        for(int i = 0; i < n - 1; i++)
        {
            currEventTime = endTime[i] - startTime[i];
            maxConsicutiveTime = freeTime[i] + freeTime[i + 1];
            if(currEventTime <= max(leftMaxFree[i], rightMaxFree[i + 1]))
                maxConsicutiveTime += currEventTime;
            ans = max(ans, maxConsicutiveTime);
        }
        return ans;
    }
};