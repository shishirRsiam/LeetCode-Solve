class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) 
    {
        int apSum = 0, ans = 0;
        for(int v:apple) apSum += v;

        sort(capacity.rbegin(), capacity.rend());
        for(int &v : capacity)
        {
            ans += 1;
            apSum -= v;
            if(apSum <= 0) break;
        }
        return ans;
    }
};