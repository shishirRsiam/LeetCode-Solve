class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end());
        int a = meetings[0][0], b = meetings[0][1];

        int minus = 0, x, y;
        for (auto vec : meetings)
        {
            x = vec[0], y = vec[1];
            if (x >= a and x <= b)
                b = max(b, y);
            else
            {
                minus += (b - a + 1);
                a = x, b = y;
            }
        }
        minus += (b - a + 1);
        return days - minus;
    }
};