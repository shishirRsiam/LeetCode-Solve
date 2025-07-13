class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        priority_queue<int> maxHeapG, maxHeapS;
        for(const int &val : g)
            maxHeapG.push(val);
        for(const int &val : s)
            maxHeapS.push(val);

        int ans = 0;
        while(not maxHeapG.empty() and not maxHeapS.empty())
        {
            if(maxHeapG.top() > maxHeapS.top()) maxHeapG.pop();
            else 
            {
                ans += 1;
                maxHeapG.pop();
                maxHeapS.pop();
            }
        }
        return ans;
    }
};