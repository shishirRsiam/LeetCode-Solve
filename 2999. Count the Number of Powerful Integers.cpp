class Solution {
public:
    long long solve(string& str, string& inputSuffix, int limit) {
        if (str.length() < inputSuffix.length()) return 0;

        long long count = 0;
        int remainingLenth = str.length() - inputSuffix.length();
        string lastString = str.substr(remainingLenth);

        for (int i = 0; i < remainingLenth; i++) 
        {
            int digit = str[i] - '0';

            if (digit <= limit) count += digit * pow(limit + 1, remainingLenth - i - 1);
            else 
            {
                count += pow(limit + 1, remainingLenth - i);
                return count;
            }
        }

        if (lastString >= inputSuffix) count += 1;
        return count;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) 
    {
        string startStr = to_string(start - 1);
        string endStr = to_string(finish);
        return solve(endStr, s, limit) - solve(startStr, s, limit);
    }
};