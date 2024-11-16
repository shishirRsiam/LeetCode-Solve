class NumArray {
public:
    vector<int>pref;
    NumArray(vector<int>& nums) 
    {
        pref.push_back(0); 
        for(auto val:nums)
            pref.push_back(pref.back() + val);;
    }
    
    int sumRange(int left, int right) {
        return pref[right + 1] - pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */