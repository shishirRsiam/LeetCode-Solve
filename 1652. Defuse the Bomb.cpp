class Solution {
public:
    void addNums(vector<int> &nums, vector<int> &code)
    {
        for(auto val:code) 
            nums.push_back(val);
    }
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();
        vector<int>ans(n);
        if(k == 0) return ans;
        auto nums = code;
        addNums(nums, code);
        addNums(nums, code);

        for(int i = n; i < n + n; i++)
        {
            int sum = 0;
            if(k < 0)
            {
                for(int j = i - 1; j >= i - -k; j--)
                {
                    sum += nums[j];
                    cout<<nums[j]<<" ";
                }
                cout<<endl;
            }
            else
            {
                for(int j = i + 1; j <= i + k; j++)
                {
                    sum += nums[j];
                    cout<<nums[j]<<" ";
                }
                cout<<endl;
            }
            ans[i - n] = sum;
        }
        return ans;
    }
};