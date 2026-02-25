class Solution {
public:
    class cmp
    {
        public:
        bool operator()(pair<int,int>&a, pair<int,int>&b)
        {
            if(a.second==b.second) return a.first > b.first;
            return a.second > b.second;
        }
    };
    vector<int> sortByBits(vector<int>& arr) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>,cmp>pq;

        for(int v:arr)
        {
            int tmp = v, cnt = 0;
            while(tmp>0)
            {
                if(tmp%2) cnt++;
                tmp/=2;
            }
            pq.push({v,cnt});
            // cout<<v<<" "<<cnt<<endl;
        }
        
        vector<int>ans;
        while(!pq.empty())
        {
            auto x = pq.top(); pq.pop();
            ans.push_back(x.first);
        }
        return ans;
    }
};