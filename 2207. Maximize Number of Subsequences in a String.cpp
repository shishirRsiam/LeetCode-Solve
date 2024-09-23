class Solution
{
public:
    long long maximumSubsequenceCount(string text, string pattern)
    {
        long ans = 0;
        char ch1 = pattern[0], ch2 = pattern[1];
        int p1 = count(text.begin(), text.end(), ch1);
        int p2 = count(text.begin(), text.end(), ch2);

        if (p1 >= p2)
            text += ch2;
        else
            text.insert(text.begin(), ch1);

        int count = 0;
        for (char ch : text)
        {
            if (ch == ch2 and count)
                ans += count;
            count += ch == ch1;
        }
        return ans;
    }
};