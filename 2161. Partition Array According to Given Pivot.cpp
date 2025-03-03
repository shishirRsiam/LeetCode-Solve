class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int x) {
            vector<int>a;
            vector<int>b;
            vector<int>c;
    
            for(int v:nums)
            {
                if(v==x) c.push_back(v);
                else if(v < x) a.push_back(v);    
                else b.push_back(v);
            }
    
            a.insert(a.end(),c.begin(),c.end());
            a.insert(a.end(),b.begin(),b.end());
            return a;
        }
    };