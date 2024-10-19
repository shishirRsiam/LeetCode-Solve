class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int ans = num, n = s.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(s[i], s[j]);
                ans = max(ans, stoi(s));
                swap(s[i], s[j]);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int maxIdx = i;
            char maxChar = s[i];
            for (int j = i + 1; j < n; j++)
                if (s[maxIdx] <= s[j])
                    maxIdx = j;

            if (s[i] != s[maxIdx])
            {
                swap(s[i], s[maxIdx]);
                break;
            }
        }
        return stoi(s);
    }
};