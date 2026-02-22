class Solution {
public:
    int binaryGap(int n) 
    {
        vector<int>a;
        while(n>0)
        {
            int tmp = n%2;
            a.push_back(tmp);
            n/=2;
        }
        reverse(a.begin(),a.end());

        int ans = 0, size = a.size();
        int idx = -1;
        for(int i=0;i<size;i++)
        {
            if(a[i]==1)
            {
                if(idx == -1) idx = i;
                else 
                {
                    ans = max(ans, i-idx);
                    idx = i;
                }
            }
        }
        return ans;
    }
};