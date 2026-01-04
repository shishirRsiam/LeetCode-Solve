class Solution {
public:
    void divisor(int n, int &sum)
    {
        vector<int> arr;
        for(int i = 1; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                arr.push_back(i);
                if(n / i != i)
                    arr.push_back(n / i);
            }
        }
        if (arr.size() == 4)
            for (auto val : arr)
                sum += val;
    }
    int sumFourDivisors(vector<int> &nums)
    {
        int sum = 0;
        for(auto val : nums)
            divisor(val, sum);
        return sum;
    }
};