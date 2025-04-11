class Solution {
public:
    int countSymmetricIntegers(int low, int high) 
    {
        int ans = 0;
        for(int num = low; num <= high; num++)
        {
            
            auto s = to_string(num);
            int leftSum = 0, rightSum = 0, n = s.size();
            if(n % 2) continue;
            for(int i = 0; i < n / 2; i++)
            {
                leftSum += s[i];
                rightSum += s[n - i - 1];
            }
            ans += leftSum == rightSum;
        }
        return ans;
    }
};