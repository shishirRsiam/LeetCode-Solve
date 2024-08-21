class Solution {
public:
    int triangularSum(vector<int>& nums) 
    {
        int n, val;
        vector<int>temp, arr = nums; 
        while(arr.size() > 1)
        {
            n = arr.size();
            for(int i=0;i<n-1;i++)
            {
                val = arr[i] + arr[i+1];
                temp.push_back(val%10);
            }
            arr = temp;
            temp.clear();
        }   
        return arr[0];
    }
};