
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        priority_queue<long long>pq;
        for(int v:happiness) pq.push(v);
        
        int i = 0;
        long long ans = 0;
        while(k--)
        {
            long long cur = pq.top() - i;
            if(cur <= 0) break;
            ans += cur;
            pq.pop();
            i++;
        }
        return ans;
    }
};