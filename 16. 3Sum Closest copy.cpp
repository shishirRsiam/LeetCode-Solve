class Solution {
public:
    int threeSumClosest(vector<int>& n, int t) 
    {
        sort(n.begin(),n.end());

        int sum = 0, ans = n[0] + n[1] + n[2];
        int sz = n.size();
        for(int i=0;i<sz;i++)
        {
            int l=i+1, r = sz-1;
            while(l<r)
            {
                sum = n[i]+n[l]+n[r];
                if(sum==t) return sum;

                if(sum<t) l++;
                else r--;

                if(abs(sum-t) < abs(ans-t)) ans = sum;
            }
        }
        return ans;
    }
};
