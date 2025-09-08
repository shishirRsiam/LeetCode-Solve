class Solution {
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for(int i = 1; i < n; i++)
        {
            string num1 = to_string(i);
            string num2 = to_string(n - i);
            if(num1.find('0') == -1 and num2.find('0') == -1)
                return {i, n - i};
        }
        return {0};
    }
};