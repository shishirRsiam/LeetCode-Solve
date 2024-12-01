class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(i != j and arr[j]*2 == arr[i]) 
                    return true;
        }
        return false;
    }
};



class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        map<int,int>mp;
        mp[0] = -1;
        for(auto val:arr) mp[val]++;
        for(auto val:arr)
        {
            if(val%2) 
            {
                if(mp[val+val]) return true;
            }
            else if(mp[val/2]) return true;
        }
        return false;
    }
};