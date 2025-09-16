class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        vector<long> st;
        for (int &num : nums) 
        {
            long cur = num;
            while (!st.empty()) 
            {
                long g = gcd(st.back(), cur);
                if (g == 1) break;

                cur = (st.back() / g) * cur; // LCM
                st.pop_back();
            }
            st.push_back(cur);
        }
        return vector<int>(begin(st), end(st));
    }
};