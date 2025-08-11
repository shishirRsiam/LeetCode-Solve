class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        string target = to_string(n), temp;
        sort(target.begin(), target.end());
        for (int i = 0; i <= 32; i++)
        {
            long long val = pow(2, i);
            temp = to_string(val);
            sort(temp.begin(), temp.end());
            if (temp == target)
                return true;
        }
        return false;
    }
};