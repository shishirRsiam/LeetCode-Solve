class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        priority_queue<int> maxHeapPlayers, maxHeapTrainers;
        for(const int &val : players)
            maxHeapPlayers.push(val);
        for(const int &val : trainers)
            maxHeapTrainers.push(val);

        int ans = 0;
        while(not maxHeapPlayers.empty() and not maxHeapTrainers.empty())
        {
            if(maxHeapPlayers.top() > maxHeapTrainers.top()) maxHeapPlayers.pop();
            else 
            {
                ans += 1;
                maxHeapPlayers.pop();
                maxHeapTrainers.pop();
            }
        }
        return ans;
    }
};