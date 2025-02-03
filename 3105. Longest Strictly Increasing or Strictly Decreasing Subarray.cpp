class Solution {
public:
    int ok(vector<int>&a)
    {
        int n = a.size();
        int mx = 1, cur = 1;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1]) cur++;
            else 
            {
                mx = max(mx, cur);
                cur = 1;
            }
        }
        return max(cur, mx);
    }
    int ok2(vector<int>&a)
    {
        int n = a.size();
        int mx = 1, cur = 1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1]) cur++;
            else 
            {
                mx = max(mx, cur);
                cur = 1;
            }
        }
        return max(cur, mx);
    }
    int longestMonotonicSubarray(vector<int>& nums) 
    {
        return max(ok(nums), ok2(nums));
    }
};